/**
 * Create a namespace so we can reuse the name "pair", which also
 * appears in the std namespace.
 */
namespace my_pair {
  /**
   * If a set of functions or classes have the same functionality for
   * different data types, this becomes a good class template. The class
   * can also hold state data about itself. A class template can be
   * implemented in C++ as either a class or a struct. A struct behaves
   * much like a class does, except that its data/methods are public by
   * default, whereas data/methods for a class are private by default.
   * This template class stores two elements of any valid datatype.
   */
  template<typename T>
  class pair {
  public:
#if PASS_BY_VALUE == 0
    pair(const T &f, const T &s)
      : first(f),
        second(s) {}
#else
    pair (T f, T s) {
      first = f;
      second = s;
    }
#endif /* PASS_BY_VALUE */

    T max();

    T first;
    T second;
  };

  /** 
   * Any template functions defined outside the class template body,
   * must always use the full template definition statement, and
   * generally must be in the same logical source file as the template
   * class declaration. Here is the function implemented along with a
   * small program using this class template.
   */
  template<typename T>
  T pair<T>::max() {
    return first < second ? second : first;
  }
}

