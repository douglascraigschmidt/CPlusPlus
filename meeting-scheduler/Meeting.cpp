#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>

#include "Meeting.h"

Meeting::Meeting (char **argv)
  : title_ (argv[0]), 
    day_ (Meeting::day_of_week (*argv[1])),
    start_time_ (atoi (argv[2])),
    finish_time_ (atoi (argv[3]))
{
  // std::cout << title_ << " " << "" << day_ << " " << start_time_ << " " << finish_time_ << std::endl;
}

Meeting::Day_Of_Week
Meeting::day_of_week (char c) {
  switch (c) 
    {
    case 'M': return Meeting::MO;
    case 'T': return Meeting::TU;
    case 'W': return Meeting::WE;
    case 'R': return Meeting::TH;
    case 'F': return Meeting::FR;
    case 'S': return Meeting::SA;
    case 'U': return Meeting::SU;
    default:
      assert (!"not a week day");
      return Meeting::MO;
    }
}

Meeting::Meeting (const std::string &title,
                  Day_Of_Week day,
                  size_t start, size_t finish)
  : title_ (title), 
    day_ (day),
    start_time_ (start),
    finish_time_ (finish) {
}

Meeting::Meeting (const Meeting &m)
 : title_ (m.title_), 
   day_ (m.day_),
   start_time_ (m.start_time_),
   finish_time_ (m.finish_time_) {
}

Meeting &
Meeting::operator = (const Meeting &m) {
  if (this != &m) {
    title_ = m.title_;
    day_ = m.day_;
    start_time_ = m.start_time_;
    finish_time_ = m.finish_time_;
  }
  return *this;
}

bool 
Meeting::operator== (const Meeting &m) const { 
  return day_ == m.day_ 
    && ((start_time_ <= m.start_time_ 
         && m.start_time_ <= finish_time_) 
        || (m.start_time_ <= start_time_ &&
            start_time_ <= m.finish_time_));
}

bool 
Meeting::operator < (const Meeting &m) const {
  return day_ < m.day_
    || (day_ == m.day_
        && start_time_ < m.start_time_)
    || (day_ == m.day_
        && start_time_ == m.start_time_
        && finish_time_ < m.finish_time_);
}

std::ostream &
operator << (std::ostream &os, const Meeting &m) {
  std::string d;
  switch (m.day_) {
  case Meeting::MO: d="M "; break;
  case Meeting::TU: d="T "; break;
  case Meeting::WE: d="W "; break;
  case Meeting::TH: d="R "; break;
  case Meeting::FR: d="F "; break;
  case Meeting::SA: d="S "; break;
  case Meeting::SU: d="U "; break;
  }
  return os << m.title_
            << std::string(" ")
            << d
            << m.start_time_
            << std::string(" ")
            << m.finish_time_;
}
