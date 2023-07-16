#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

void waitForPermission(size_t& eatCount, condition_variable_any& cv, mutex& permitsLock, size_t& permits) {
    permitsLock.lock();
    while (permits == 0) {
        cv.wait(permitsLock);
    }
    eatCount--;
    permits--;
    permitsLock.unlock();
}

void grantPermission(size_t& permits, condition_variable_any& cv, mutex& permitsLock) {
    permitsLock.lock();
    permits++;
    cv.notify_all();
    permitsLock.unlock();
}

void eat(size_t id, mutex& left, mutex& right, size_t& eatCount, mutex& permitsLock, size_t& permits, condition_variable_any& cv) {
    waitForPermission(eatCount, cv, permitsLock, permits);
    left.lock();
    right.lock();
    cout << id << " starts eating." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << id << " all done eating." << endl;
    left.unlock();
    right.unlock();
    grantPermission(permits, cv, permitsLock);
}

//int main() {
//    mutex forks[5];
//    mutex permitsLock;
//    int eatCount = 4;
//    size_t permits = 2; // Number of available permits
//    thread philosophers[5];
//    condition_variable_any cv;
//
//    for (size_t i = 0; i < 5; i++) {
//        mutex& left = forks[i];
//        mutex& right = forks[(i + 1) % 5];
//        philosophers[i] = thread(eat, i, ref(left), ref(right), ref(eatCount), ref(permitsLock), ref(permits), ref(cv));
//    }
//
//    for (thread& p : philosophers) {
//        p.join();
//    }
//
//    return 0;
//}