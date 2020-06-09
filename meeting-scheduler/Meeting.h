#ifndef _MEETING_H
#define _MEETING_H

#include <string>

struct Meeting {
  enum Day_Of_Week {MO, TU, WE, TH, FR, SA, SU};

  static Day_Of_Week day_of_week (char c);

  Meeting (const std::string &title,
           Day_Of_Week day,
           size_t start_time,
           size_t finish_time);
  Meeting (const Meeting &m);
  explicit Meeting (char **argv);

  Meeting &operator= (const Meeting &m);

  bool operator< (const Meeting &m) const;
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

std::ostream &operator << (std::ostream &os, const Meeting &m);

#endif /* _MEETING_H */


