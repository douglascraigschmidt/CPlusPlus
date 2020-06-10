#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <sstream>

#include "meeting.h"

/**
 * Constructor that converts an argv array into a meeting object.
 */
meeting::meeting (char **argv)
  : title_ (argv[0]), 
    day_ (meeting::day_of_week (*argv[1])) {
  std::stringstream a1(argv[2]);
  std::stringstream a2(argv[3]);

  a1 >> start_time_;
  a2 >> finish_time_;
    // std::cout << title_ << " " << "" << day_ << " " << start_time_ << " " << finish_time_ << std::endl;
}

/**
 * Factory method.
 */
enum meeting::day_of_week
meeting::day_of_week (char c) {
  switch (c) {
    case 'M': return meeting::MO;
    case 'T': return meeting::TU;
    case 'W': return meeting::WE;
    case 'R': return meeting::TH;
    case 'F': return meeting::FR;
    case 'S': return meeting::SA;
    case 'U': return meeting::SU;
    default:
      assert (!"not a week day");
      return meeting::MO;
  }
}

/**
 * Constructor that initializes the data members.
 */
meeting::meeting (const std::string &title,
                  enum day_of_week day,
                  size_t start,
                  size_t finish)
  : title_ (title), 
    day_ (day),
    start_time_ (start),
    finish_time_ (finish) {
}

/**
 * Copy constructor.
 */
meeting::meeting (const meeting &m)
 : title_ (m.title_), 
   day_ (m.day_),
   start_time_ (m.start_time_),
   finish_time_ (m.finish_time_) {
}

/**
 * Copy assignment operator.
 */
meeting &
meeting::operator = (const meeting &m) {
  // Check for self-assignment.
  if (this != &m) {
    title_ = m.title_;
    day_ = m.day_;
    start_time_ = m.start_time_;
    finish_time_ = m.finish_time_;
  }
  return *this;
}

/**
 * "Equality" operator that detects overlaps in meeting times.
 */
bool 
meeting::operator== (const meeting &m) const {
  // This is an example conflict:
  // CS242 T 1230 1430
  // CS281 T 1300 1430
  return day_ == m.day_ 
    && ((start_time_ <= m.start_time_ 
         && m.start_time_ <= finish_time_) 
        || (m.start_time_ <= start_time_ 
            && start_time_ <= m.finish_time_));
}

/**
 * Operator that checks for less than relation.
 */
bool
meeting::operator < (const meeting &m) const {
    return day_ < m.day_
           || (day_ == m.day_
               && start_time_ < m.start_time_)
           || (day_ == m.day_
               && start_time_ == m.start_time_
               && finish_time_ < m.finish_time_);
}

/**
 * Insertion operator that prints the output.
 */
std::ostream &
operator << (std::ostream &os, const meeting &m) {
  std::string d;
  switch (m.day_) {
  case meeting::MO: d="M "; break;
  case meeting::TU: d="T "; break;
  case meeting::WE: d="W "; break;
  case meeting::TH: d="R "; break;
  case meeting::FR: d="F "; break;
  case meeting::SA: d="S "; break;
  case meeting::SU: d="U "; break;
  }
  return os << m.title_
            << std::string(" ")
            << d
            << m.start_time_
            << std::string(" ")
            << m.finish_time_;
}
