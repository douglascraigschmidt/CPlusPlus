// -std=c++0x
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <set>

#include "print_conflicts.h"
#include "argv_iterator.h"
#include "Meeting.h"

template <typename Input_Iterator, typename Output_Iterator>
static void 
check_for_conflicts (Input_Iterator begin,
                     Output_Iterator end) {
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
