#include <stdexcept>
#include "throw_exception.h"

throw_exception::throw_exception(int j)
  : j_(j){}

throw_exception &
throw_exception::operator=(const throw_exception &rhs) {
  if (++i_ == 3) {
    throw std::out_of_range("index out of range");
  }
  return *this;
}

throw_exception::operator int() {
  return j_;
}

int 
throw_exception::i_ = 0;

