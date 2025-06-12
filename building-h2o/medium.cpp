#include <mutex>
#include <semaphore>
#include <functional>

using namespace std;

class H2O {
private:
    counting_semaphore<2> hReady{2};  // Limit to 2 hydrogens per molecule
    counting_semaphore<1> oReady{1};  // Limit to 1 oxygen per molecule
    binary_semaphore barrier{0};      // Sync the 3 threads to form water

    mutex mtx;
    int count = 0; // Counts how many threads (H or O) reached the barrier

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        hReady.acquire();

        // Wait at the barrier
        bool last = false;
        {
            lock_guard<mutex> lock(mtx);
            count++;
            if (count == 3) {
                last = true;
            }
        }

        if (last) {
            // Last thread releases the barrier for all 3
            barrier.release();
            barrier.release();
            barrier.release();
        }

        barrier.acquire(); // Wait for all 3 to arrive

        releaseHydrogen();

        {
            lock_guard<mutex> lock(mtx);
            count--;
            if (count == 0) {
                // Reset for next molecule
                hReady.release(2);
                oReady.release();
            }
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        oReady.acquire();

        // Wait at the barrier
        bool last = false;
        {
            lock_guard<mutex> lock(mtx);
            count++;
            if (count == 3) {
                last = true;
            }
        }

        if (last) {
            // Last thread releases the barrier for all 3
            barrier.release();
            barrier.release();
            barrier.release();
        }

        barrier.acquire(); // Wait for all 3 to arrive

        releaseOxygen();

        {
            lock_guard<mutex> lock(mtx);
            count--;
            if (count == 0) {
                hReady.release(2);
                oReady.release();
            }
        }
    }
};
