class FooBar {
private:
    int n;
    int x = 1;
    mutex m;
    condition_variable cv;

public:
    FooBar(int n) : n(n) {}

    void foo(function<void()> printFoo) {
        while (true) {
            unique_lock<mutex> lock(m);

            while (x <= 2*n && x % 2 == 0)
                cv.wait(lock);

            if (x > 2*n) return;

            printFoo();
            x++;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        while (true) {
            unique_lock<mutex> lock(m);

            while (x <= 2*n && x % 2 == 1)
                cv.wait(lock);

            if (x > 2*n) return;

            printBar();
            x++;
            cv.notify_all();
        }
    }
};
