#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <set>

#include "print_conflicts.h"
#include "argv_iterator.h"
#include "meeting.h"

/**
 * Forward declaration.
 */
template <typename InputIterator>
static void 
check_for_conflicts (InputIterator begin,
                     InputIterator end);

/**
 * This program reads a list of meeting times/dates provided as
 * argc/argv command-line parameters to the program, detects/prints
 * any "conflicts" (i.e., overlaps in time/date), and writes out the
 * schedule to the output.
 */
int 
main (int argc, char *argv[]) {
  // Create a vector of meeting objects.
  std::vector<meeting> schedule;

  // Use the argv_iterator to convert the argc/argv command-line
  // parameters into an iterator and copy the contents into the
  // schedule vector.
  std::copy (argv_iterator<meeting> (argc - 1, argv + 1, 4),
             argv_iterator<meeting> (),
             std::back_inserter (schedule));

  // Sort the contents of the vector.
  std::sort (schedule.begin (), schedule.end ());

  // Detect/print any conflicts.
  check_for_conflicts (schedule.begin (), schedule.end ());

  // Print out schedule, using STL output stream iterator adapter.
  std::copy (schedule.begin (),
             schedule.end (), 
             std::ostream_iterator<meeting> (std::cout, "\n"));

  return 0;
}

/**
 * This method checks for conflicts in the schedule designated by the
 * range [begin, end).
 */
template <typename InputIterator>
static void 
check_for_conflicts (InputIterator begin,
                     InputIterator end) {
#if 1  
  // Find and print any conflicts using a for loop.
  for (auto iter = begin; iter != end; ++iter) {
    if (iter != end - 1 && *iter == *(iter + 1))
      std::cout << "CONFLICT:" << std::endl 
                << " " << *iter << std::endl
                << " " << *(iter + 1) << std::endl 
                << std::endl;
  }
#else
  // Find and print any conflicts using the STL transform() algorithm.
  std::transform (begin, end - 1,
                  begin + 1,
                  begin,
                  print_conflicts (std::cout));
#endif
}

