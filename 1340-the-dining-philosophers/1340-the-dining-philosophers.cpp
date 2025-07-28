class Semaphore {
    private:
        int count;
        condition_variable cv;
        mutex m;
    public:
        Semaphore() {};
        Semaphore(int cnt) : count(cnt) {};

        void setCount(int a){
            count = a;
        }

        inline void wait(){
            unique_lock<mutex> lock(m);
            count--;
            if(count < 0){
                cv.wait(lock);
            }
        }

        inline void signal(){
            unique_lock<mutex> lock(m);
            count++;
            if(count <= 0){
                cv.notify_one();
            }
        }
};

class DiningPhilosophers {
private:
    Semaphore fork[5];
public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        if (left > right) swap(left, right);

        fork[left].wait();
        fork[right].wait();

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        fork[left].signal();
        fork[right].signal();
    }
};