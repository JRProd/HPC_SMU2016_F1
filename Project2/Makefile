###################################################################
#  Makefile for project 2
#
#  Daniel R. Reynolds
#  SMU Mathematics
#  Math 3316
#  16 September 2015
###################################################################

###################################################################
# Edited by Jake Rowland for Project 2 of HPC
# Math 3316
# 10/6/2016
###################################################################


# compilation definitions
CXX = g++
CXXFLAGS = -O -std=c++11

# makefile targets

all : vandermonde.exe test_newton.exe kepler.exe

kepler.exe : kepler.cpp newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

vandermonde.exe : vandermonde.cpp matrix.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

test_newton.exe : newton.cpp test_newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
