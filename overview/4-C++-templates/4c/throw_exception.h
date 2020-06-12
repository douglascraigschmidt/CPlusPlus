#ifndef _THROW_EXCEPTION_H
#define _THROW_EXCEPTION_H

class throw_exception {
public:
  throw_exception(int j = 0);

  throw_exception &operator=(const throw_exception &rhs);

  operator int();

private:
  static int i_;
  int j_;
};

#endif /* _THROW_EXCEPTION_H */
