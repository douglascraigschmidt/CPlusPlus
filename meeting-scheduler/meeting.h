#ifndef _MEETING_H
#define _MEETING_H

#include <string>

/**
 * This struct stores information about the time and date of a
 * meeting.
 */
struct meeting {
  /**
   * Enum literals for days of the week.
   */
  enum day_of_week {MO, TU, WE, TH, FR, SA, SU};

  /**
   * Factory method that converts a character to the day_of_week enum.
   */
  static day_of_week day_of_week (char c);

  /**
   * Constructor initializes the data members.
   */
  meeting (const std::string &title,
           enum day_of_week day,
           size_t start_time,
           size_t finish_time);

  /**
   * Copy constructor.
   */
  meeting (const meeting &m);

  /**
   * Constructor that converts an argv into a meeting object.
   */
  explicit meeting (char **argv);

  /**
   * Copy assignment operator.
   */
  meeting &operator= (const meeting &m);

  /**
   * Relational operators.
   */
  bool operator< (const meeting &m) const;
  bool operator== (const meeting &m) const;

  /**
   * Title of the meeting.
   */
  std::string title_;

  /**
   * Week day of meeting.
   */
  enum day_of_week day_;

  /**
   * meeting start time in HHMM format.
   */
  size_t start_time_;

  /** 
   * meeting finish time in HHMM format
   */
  size_t finish_time_;
};

/**
 * Insertion operator.
 */
std::ostream &operator << (std::ostream &os, const meeting &m);

#endif /* _MEETING_H */


