class semaphore{
    public:
    mutex m;
    condition_variable cv;
    int count;
    semaphore(){}
    semaphore(int a){
        count=a;


    }
    inline void setcount(int a){
        count=a;
    }

    inline void signal(){
        unique_lock<mutex> lock(m);
        count++;
        if(count>0)cv.notify_one();
    }
    inline void wait(){
        unique_lock<mutex>lock(m);
        while(count<=0)cv.wait(lock);
        count--;
    }
};
class DiningPhilosophers {
public:
 semaphore fork[5];
  mutex m;

    DiningPhilosophers() {
        for(int i=0;i<5;i++){
            fork[i].setcount(1);
        }
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        {
            unique_lock<mutex>lock(m);
            fork[(philosopher + 1) % 5].wait();
            fork[philosopher].wait();
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
         fork[(1+philosopher)%5].signal();
        putRightFork();
       
       fork[philosopher].signal();

		
    }
};