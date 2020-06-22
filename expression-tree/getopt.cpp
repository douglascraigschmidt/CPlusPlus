/*
 * getopt - get option letter from argv
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

static char	*scan = 0;	/* Private scan pointer. */

extern char	*index();

namespace parsing {
  char	*optarg;	/* Global argument pointer. */
  int	optind = 0;	/* Global argv index. */

  std::string getfilename (std::string arg)
  {
    std::string::size_type lastFound = arg.find_last_of('\\');

    if (lastFound == std::string::npos)
    {
      // we didn't find a Windows path, try a Unix path
      lastFound = arg.find_last_of('/');
    }

    // if we found a match and it did not occur on the last character,
    // return the string from the match to the end

    if (lastFound != std::string::npos && lastFound < arg.length() - 1)
    {
      return arg.substr(lastFound+1);
    }

    // otherwise, return the incoming string

    return arg;
  }

  std::string getpath (std::string arg)
  {
    // first, try to get the Windows path

    std::string::size_type lastFound = arg.find_last_of('\\');

    if (lastFound == std::string::npos)
    {
      // we didn't find a Windows path, try a Unix path
      lastFound = arg.find_last_of('/');
    }

    // if we found a match
    // return the string from beginning to and including the match

    if (lastFound != std::string::npos)
    {
      return arg.substr(0,lastFound+1);
    }

    // otherwise, return an empty string

    return "";
  }

  int
  getopt(int argc, char *argv[], char *optstring)
  {
    char c;
    char *place;

    optarg = 0;

    if (scan == 0 || *scan == '\0') {
      if (optind == 0)
        optind++;
	
      if (optind >= argc || argv[optind][0] != '-' || argv[optind][1] == '\0')
        return(EOF);
      if (::strcmp(argv[optind], "--")==0) {
        optind++;
        return(EOF);
      }
	
      scan = argv[optind]+1;
      optind++;
    }

    c = *scan++;
    place = ::strchr(optstring, c);

    if (place == 0 || c == ':') {
      fprintf(stderr, "%s: unknown option -%c\n", argv[0], c);
      return('?');
    }

    place++;
    if (*place == ':') {
      if (*scan != '\0') {
        optarg = scan;
        scan = 0;
      } else if (optind < argc) {
        optarg = argv[optind];
        optind++;
      } else {
        fprintf(stderr, "%s: -%c argument missing\n", argv[0], c);
        return('?');
      }
    }

    return(c);
  }
}
