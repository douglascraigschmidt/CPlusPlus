#ifdef _PRINT_CONFLICTS_H
#define _PRINT_CONFLICTS_H

struct print_conflicts {
  print_conflicts (std::ostream &os): os_ (os) {}

  Meeting operator () (const Meeting &lhs, const Meeting &rhs) {
    if (lhs == rhs)
      os_ << "CONFLICT:" << std::endl << " " << lhs << std::endl
          << " " << rhs << std::endl << std::endl;

    return lhs;
  }

  std::ostream &os_;
};

#endif /* _PRINT_CONFLICTS_H */
