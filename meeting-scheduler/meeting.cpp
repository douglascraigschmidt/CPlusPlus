// -std=c++0x
#include <iostream>
#include <assert.h>
#include <string>
#include <stdlib.h>    
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <set>

struct Meeting {
  enum Day_Of_Week {MO, TU, WE, TH, FR, SA, SU};

  static Day_Of_Week day_of_week (char c);

  Meeting (const std::string &title,
           Day_Of_Week day,
           size_t start_time,
           size_t finish_time);
  Meeting (const Meeting &m);
  Meeting (char **argv);

  Meeting &operator= (const Meeting &m);

  bool operator < (const Meeting &m) const;
  bool operator== (const Meeting &m) const;

  // Title of the meeting
  std::string title_;

  // Week day of meeting
  Day_Of_Week day_;

  // Meeting start time in HHMM format
  size_t start_time_;

  // Meeting finish time in HHMM format
  size_t finish_time_;
};

Meeting::Meeting (char **argv)
  : title_ (argv[0]), 
    day_ (Meeting::day_of_week (*argv[1])),
    start_time_ (atoi (argv[2])),
    finish_time_ (atoi (argv[3]))
{
  // std::cout << title_ << " " << "" << day_ << " " << start_time_ << " " << finish_time_ << std::endl;
}

Meeting::Day_Of_Week
Meeting::day_of_week (char c)
{
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
    finish_time_ (finish)
{
}

Meeting::Meeting (const Meeting &m)
 : title_ (m.title_), 
   day_ (m.day_),
   start_time_ (m.start_time_),
   finish_time_ (m.finish_time_)
{
}

Meeting &
Meeting::operator = (const Meeting &m) 
{
  if (this != &m)
    {
      title_ = m.title_;
      day_ = m.day_;
      start_time_ = m.start_time_;
      finish_time_ = m.finish_time_;
    }
  return *this;
}

bool 
Meeting::operator== (const Meeting &m) const 
{
  return day_ == m.day_ 
    && ((start_time_ <= m.start_time_ 
         && m.start_time_ <= finish_time_) 
        || (m.start_time_ <= start_time_ &&
            start_time_ <= m.finish_time_));
}

bool 
Meeting::operator < (const Meeting &m) const
{
  return day_ < m.day_
    || (day_ == m.day_
        && start_time_ < m.start_time_)
    || (day_ == m.day_
        && start_time_ == m.start_time_
        && finish_time_ < m.finish_time_);
}

std::ostream &
operator << (std::ostream &os, const Meeting & m)
{
  const char *d = "   ";
  switch (m.day_) {
  case Meeting::MO: d="M "; break;
  case Meeting::TU: d="T "; break;
  case Meeting::WE: d="W "; break;
  case Meeting::TH: d="R "; break;
  case Meeting::FR: d="F "; break;
  case Meeting::SA: d="S "; break;
  case Meeting::SU: d="U "; break;
  }
  return os << m.title_ << " " 
            << d
            << m.start_time_ << " "
            << m.finish_time_;
}

template <typename T>
class argv_iterator : public std::iterator <std::forward_iterator_tag, T>
{
public:
  argv_iterator (void) {}
  argv_iterator (int argc, char **argv, int increment)
    : argc_ (argc),
      argv_ (argv),
      base_argv_ (argv),
      increment_ (increment) {}

  bool operator != (const argv_iterator &)
  {
    return argv_ != (base_argv_ + argc_);
  }

  T operator *()
  { 
    return T (argv_);
  }

  void operator++ () { argv_ += increment_; }

private:
  int argc_;
  char **argv_;
  char **base_argv_;
  int increment_;
};

struct print_conflicts 
{
  print_conflicts (std::ostream &os): os_ (os) {}

  Meeting operator () (const Meeting &lhs, const Meeting &rhs)
  {
    if (lhs == rhs)
      os_ << "CONFLICT:" << std::endl << " " << lhs << std::endl
          << " " << rhs << std::endl << std::endl;

    return lhs;
  }

  std::ostream &os_;
};

template <typename Input_Iterator, typename Output_Iterator>
void check_for_conflicts (Input_Iterator begin, Output_Iterator end) {
#if 1  
  for (auto iter = begin; iter != end; ++iter) {
    if (iter != end - 1 && *iter == *(iter + 1))
      std::cout << "CONFLICT:" << std::endl << " " << *iter << std::endl
                << " " << *(iter + 1) << std::endl << std::endl;
  }
#else
  // Find & print out any conflicts.
  std::transform (begin, end - 1,
                  begin + 1,
                  begin,
                  print_conflicts (std::cout));
#endif
}

int 
main (int argc, char *argv[]) 
{
  std::vector<Meeting> schedule;

  std::copy (argv_iterator<Meeting> (argc - 1, argv + 1, 4),
             argv_iterator<Meeting> (),
             std::back_inserter (schedule));
             
  std::sort (schedule.begin (), schedule.end ());

  check_for_conflicts (schedule.begin (), schedule.end ());

  // Print out schedule, using STL output stream iterator adapter.
  std::copy (schedule.begin (),
             schedule.end (), 
             std::ostream_iterator<Meeting> (std::cout, "\n"));

  return 0;
}
