#include <iostream>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include "threadpool.hpp"


void thrd_pool_test(int i){
    std::cout << ++i << " ";
}

int main () {

    threadpool pool(6);

    for (int i = 0; i < 25; ++i) {
        //Uncomment for desired function to test with
        pool.add_work(thrd_pool_test, i);
    }
    // Explicit sleep to allow threads time to enter running state
    boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
    return 0;
}
