#ifndef _SIMPLE_STRING_H
#define _SIMPLE_STRING_H

/**
 * This simple string class shows the difference between pass-by-value
 * using copy vs. move semantics in C++.  It also shows the "Rule of
 * 5", which supplants the "Rule of 3" with earlier C++ versions
 * https://en.wikipedia.org/wiki/Rule_of_three_(C++_programming).
 */
class simple_string {
public:
  simple_string();

  explicit simple_string(const char *s);

  simple_string(const simple_string &rhs) noexcept;

  simple_string(simple_string &&rhs) noexcept;

  simple_string &operator=(const simple_string &rhs) noexcept;

  simple_string &operator=(simple_string &&rhs) noexcept;

  void swap(simple_string &rhs) noexcept;

  char &operator[](size_t index);

  const char &operator[](size_t index) const;

  explicit operator const char *() const;

  ~simple_string();

private:
  char *str_{};

  static char *strnew(const char *s);
};
#endif /* _SIMPLE_STRING_H */
