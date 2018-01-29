# boost-threadpool
Simple threadpool class using boost threads and asio

## Compile
g++ -c -std=c++14 threadpool.cpp -lboost_system -lboost_thread -lpthread

You can have g++ fully optimize away the overhead of the template parameters by adding a -O4 (https://vittorioromeo.info/index/blog/passing_functions_to_functions.html):

g++ -c -O4 -std=c++14 threadpool.cpp -lboost_system -lboost_thread -lpthread
