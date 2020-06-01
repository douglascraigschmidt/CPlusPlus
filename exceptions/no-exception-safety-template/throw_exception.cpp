#include <stdexcept>
#include "throw_exception.h"

throw_exception &
throw_exception::operator=(const throw_exception &rhs) {
  if (++i_ == 10) {
    throw std::out_of_range("index out of range");
  }
  return *this;
}

int 
throw_exception::i_ = 0;

