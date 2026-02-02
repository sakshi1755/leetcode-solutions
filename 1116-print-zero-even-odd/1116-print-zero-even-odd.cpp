class ZeroEvenOdd {
private:
    int n;
    int i=1;
    int turn=0;
    mutex m;
    int l=0;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(m);
            while(l<2*n && turn!=0){
                cv.wait(lock);
            }
              if(l>=2*n)return;
            printNumber(0);
          
            l++;
            turn=1;
            cv.notify_all(); 


        }
        
    }

    void even(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(m);
            while(l<2*n && (turn==0 || i%2==1) ){
                cv.wait(lock);
            }
              if(l>=2*n)return;
            printNumber(i);
           // if(l>=2*n)return;
            l++;
            turn=0;
            i++;
            cv.notify_all(); 

        }
        
    }

    void odd(function<void(int)> printNumber) {
        while(true){
               unique_lock<mutex> lock(m);
            while(l<2*n && (turn==0 || i%2==0) ){
                cv.wait(lock);
            }
              if(l>=2*n)return;
            printNumber(i);
          //  if(l>=2*n)return;
            l++;
            turn=0;
            i++;
            cv.notify_all(); 


        }
        
    }
};