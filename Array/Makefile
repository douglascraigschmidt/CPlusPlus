#############################################################################
#
#  Makefile for assignment 1
#
#############################################################################

CXX		= g++
CFILES		= main.cpp \
		  Array.cpp 
OFILES		= main.o Array.o
DFLAGS		= -ggdb
CFLAGS		= $(DFLAGS) -std=c++0x -DRVALUE_REFERENCES # -fno-elide-constructors # -DUSE_TEMPLATES -D__INLINE__ -DUSE_EXCEPTIONS

#############################################################################
# C++ directives

.SUFFIXES: .cpp
.cpp.o:
	$(CXX) $(CFLAGS) -c $<
#############################################################################

main: $(OFILES)
	$(CXX) $(CFLAGS) -o $@ $(OFILES) $(LIBS)

clean:
	-/bin/rm -f *.o *.out *~ core

realclean: clean 
	-/bin/rm -fr main Templates.DB

depend:
	g++dep -f Makefile $(CFILES)
# DO NOT DELETE THIS LINE -- g++dep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

main.o: main.cpp Array.h Array.cpp Array.inl
Array.o: Array.cpp Array.h Array.cpp Array.inl

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
