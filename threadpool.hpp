//HBchevelle68
#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP

#include <boost/thread/thread.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/optional/optional.hpp>

class threadpool {

  private:
      boost::asio::io_service ioService;
      boost::thread_group threads;
      boost::optional<boost::asio::io_service::work> work { ioService };

  public:
      threadpool();
      threadpool(std::size_t);
      ~threadpool();
      void add_threads(std::size_t num = 1);
      template <typename F, typename... Args>
      void add_work(F f, Args... args){
          ioService.post(boost::bind(f, args...));
      };
      std::size_t size() const { return threads.size(); }
};
#endif //HREADPOOL_HPP
