#include "threadpool.hpp"


threadpool::threadpool() {

    std::size_t psize = boost::thread::hardware_concurrency();
    for (std::size_t i = 0; i < psize; ++i) {
        threads.create_thread( boost::bind(&boost::asio::io_service::run, &ioService));
    }
}

threadpool::threadpool( std::size_t psize ) {
    for (std::size_t i = 0; i < psize; ++i) {
        threads.create_thread( boost::bind(&boost::asio::io_service::run, &ioService));
    }
}

void threadpool::add_threads(size_t num) {
    for (size_t i = 0; i < num; i++) {
        threads.create_thread( boost::bind(&boost::asio::io_service::run, &ioService));
    }
}

threadpool::~threadpool() {
    work.reset();
    try {
        threads.join_all();
    }
    catch (const std::exception&) {}
}
