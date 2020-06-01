#include <mutex>
#include <condition_variable>

/**
 * Make up for the lack of a std::semaphore in C++.
 */
class semaphore {
public:
  explicit semaphore (int i);

  /**
   * Implement the semaphore "P" operation.
   */
  void acquire();

  /**
   * Implement the semaphore "V" operation.
   */
  void release();

private:
  std::mutex m_;
  std::condition_variable cond_;
  int n_;
};
