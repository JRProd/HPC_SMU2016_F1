###################################################################
#  Makefile for project 2
#
#  Daniel R. Reynolds
#  SMU Mathematics
#  Math 3316
#  16 September 2015
###################################################################

# compilation definitions
CXX = g++
CXXFLAGS = -O -std=c++11

# makefile targets

all : proj2_a.exe proj2_b.exe

proj2_a.exe : vandermonde.cpp matrix.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

proj2_b.exe : newton.cpp test_newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

all : test_bisect.exe 

test_bisect.exe : test_bisect.cpp bisection.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
