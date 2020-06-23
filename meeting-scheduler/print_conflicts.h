#ifdef _PRINT_CONFLICTS_H
#define _PRINT_CONFLICTS_H

#include "meeting.h"

/**
 * This functor detects/prints "conflicts" between two meeting
 * times/dates.
 */
struct print_conflicts {
  /**
   * This stateful functor stores where to print the output.
   */
  print_conflicts (std::ostream &os): os_ (os) {}

  /**
   * This method detects/prints "conflicts" between two meeting
   * times/dates, i.e., it looks for overlaps in the start/end times.
   */
  const meeting &operator () (const meeting &lhs, const meeting &rhs) {
    // If operator == returns true there's a conflict, so print it
    // out!
    if (lhs == rhs)
      os_ << "CONFLICT:" << std::endl << " " << lhs << std::endl
          << " " << rhs << std::endl << std::endl;

    return lhs;
  }

  std::ostream &os_;
};

#endif /* _PRINT_CONFLICTS_H */
