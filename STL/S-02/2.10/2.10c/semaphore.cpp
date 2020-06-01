#include "semaphore.h"

semaphore::semaphore (int i): n_(i) {}

/**
 * Implement the semaphore "P" operation.
 */
void 
semaphore::acquire () {
  std::unique_lock<std::mutex> lock (m_);
  cond_.wait(lock, [this] { return n_ > 0; });
  --n_;
}

/**
 * Implement the semaphore "V" operation.
 */
void 
semaphore::release () {
  std::unique_lock <std::mutex> lock (m_);
  ++n_;
  cond_.notify_one();
}
