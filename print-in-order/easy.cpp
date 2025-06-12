#include <mutex>
#include <functional>
using namespace std;

class Foo {
private:
    mutex secondLock;
    mutex thirdLock;

public:
    Foo() {
        // Initially lock the mutexes so second() and third() block until they're unlocked
        secondLock.lock();
        thirdLock.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();         // outputs "first"
        secondLock.unlock();  // allow second() to proceed
    }

    void second(function<void()> printSecond) {
        secondLock.lock();    // wait for first() to finish
        printSecond();        // outputs "second"
        secondLock.unlock();  // optional unlock
        thirdLock.unlock();   // allow third() to proceed
    }

    void third(function<void()> printThird) {
        thirdLock.lock();     // wait for second() to finish
        printThird();         // outputs "third"
        thirdLock.unlock();   // optional unlock
    }
};
