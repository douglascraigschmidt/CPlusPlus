#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>

using namespace std;

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}

template<template<typename, typename...> class container,
         typename valueType,
         typename... Args>
void print_container(ostream &os,
                     const container<valueType, Args...>& objs) {
  os << __PRETTY_FUNCTION__ << '\n';

  for (auto const &obj : objs)
    os << obj << ' ';

  os << '\n';
}

template<typename input_iterator>
void print_iterator(ostream &os,
                    input_iterator start,
                    input_iterator end) {
    os << __PRETTY_FUNCTION__ << '\n';

    while (start != end)
        os << *start++ << ' ';

    os << '\n';
}

int main() {
  std::vector<float> vf { 1.1, 2.2, 3.3, 4.4 };
  print_iterator(cout, vf.begin(), vf.end());
  print_container(cout, vf);

  std::list<char> lc { 'a', 'b', 'c', 'd' };
  print_iterator(cout, lc.begin(), lc.end());
  print_container(cout, lc);

  std::deque<int> di { 1, 2, 3, 4 };
  print_iterator(cout, di.begin(), di.end());
  print_container(cout, di);

  std::map<string, int> msi {{"larry", 100}, {"curly", 90}, {"moe", 110}};
  print_iterator(cout, msi.begin(), msi.end());
  print_container(cout, msi);

  return 0;
}
