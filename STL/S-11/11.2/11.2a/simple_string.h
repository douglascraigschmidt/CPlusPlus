#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
#pragma ide diagnostic ignored "cert-dcl21-cpp"
#ifndef _SIMPLE_STRING_H
#define _SIMPLE_STRING_H

#include <iterator>

/**
 * Forward declarations
 */
class simple_string_iterator;
class simple_string_const_iterator;

/**
 * This simple string class shows the difference between pass-by-value
 * using copy vs. move semantics in C++.  It also shows the "Rule of
 * 5", which supplants the "Rule of 3" with earlier C++ versions
 * https://en.wikipedia.org/wiki/Rule_of_three_(C++_programming).
 */
class simple_string {
public:
  // Traits defined to mimic the STL container model.
  typedef char value_type;
  typedef simple_string_iterator iterator;
  typedef simple_string_const_iterator const_iterator;
  // ...

  simple_string();

  explicit simple_string(const char *s);

  simple_string(const simple_string &rhs) noexcept;

  simple_string(simple_string &&rhs) noexcept;

  simple_string &operator=(const simple_string &rhs) noexcept;

  simple_string &operator=(simple_string &&rhs) noexcept;

  ~simple_string();

  void swap(simple_string &rhs) noexcept;

  char &operator[](size_t index);

  const char &operator[](size_t index) const;

  bool operator<(const simple_string &rhs) const;

  size_t length() const;

  explicit operator const char *() const;

  // Get an iterator that points to the beginning of the Array.
  iterator begin ();

  // Get a const interator that points to the beginning of the Array.
  const_iterator begin () const;


  // Get a const interator that points to the beginning of the Array.
  const_iterator cbegin () const;

  // Get an iterator that points to the end
  iterator end ();

  // Get a const iterator that points to the end of the list.
  const_iterator end () const;

  // Get a const iterator that points to the end of the list.
  const_iterator cend () const;

private:
  size_t len_;

  char *str_;

  char *strnew(const char *s);
};

std::ostream &
operator<<(std::ostream &os, const simple_string &string);

class simple_string_iterator :
  public std::iterator <std::bidirectional_iterator_tag, simple_string> {
  friend class simple_string;

public:
  /**
   * Dereference operator returns a reference to the item contained at
   * the current position. */
  char& operator* ();

  /**
   * Returns a const reference to the item contained at the current
   * position
   */
  const char& operator* () const;

  /**
   * Pre-increment operator (++iter)
   */
  simple_string_iterator &operator++ ();

  /**
   * Post-increment operator (iter++)
   */
  simple_string_iterator operator++ (int);

  /**
   * Pre-decrement operator (--iter)
   */
  simple_string_iterator &operator-- ();

  /**
   * Post-decrement operator (iter--)
   */
  simple_string_iterator operator-- (int);

  /**
   * Equality operator
   */
  bool operator== (const simple_string_iterator &rhs) const;

  /**
   * Non-equality operator
   */
  bool operator!= (const simple_string_iterator &lhs) const;

private:
  /**
   * Construct an simple_string_iterator at position pos.
   */
  simple_string_iterator (simple_string &simple_string, size_t pos = 0);

  /**
   * the simple_string we are dealing with
   */
  simple_string &simple_string_;

  /**
   * Our current position
   */
  mutable size_t pos_;
};

/**
 * A const_iterator does not guarantee that the current *position*
 * that it points to will not change, it only guarantees that you
 * cannot change the underlying simple_string!
 */
class simple_string_const_iterator :
  public std::iterator <std::bidirectional_iterator_tag, simple_string> {
  friend class simple_string;

public:
  /**
   * Returns a const reference to the item contained at the current
   * position (note there's no non-const operator*()!!)
   */
  const char& operator* () const;

  /**
   * Pre-increment operator
   */
  simple_string_const_iterator & operator++ ();

  /**
   * Post-increment operator
   */
  simple_string_const_iterator operator++ (int);

  /**
   * Pre-decrement operator
   */
  simple_string_const_iterator &operator-- ();

  /**
   * Post-decrement operator
   */
  simple_string_const_iterator operator-- (int);

  /**
   * Equality operator
   */
  bool operator== (const simple_string_const_iterator &rhs) const;

  /**
   * Non-equality operator
   */
  bool operator!= (const simple_string_const_iterator &lhs) const;

private:
  /**
   * Construct an iterator at position pos.
   */
  simple_string_const_iterator (const simple_string &simple_string, size_t pos = 0);

  /**
   * the simple_string we are dealing with
   */
  const simple_string &simple_string_;

  /**
   * Our current position
   */
  mutable size_t pos_;
};

#endif /* _SIMPLE_STRING_H */

#pragma clang diagnostic pop