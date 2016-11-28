###################################################################
#  Makefile for project 4
#
#  Daniel R. Reynolds
#  SMU Mathematics
#  Math 3316
#  31 October 2015
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O2 -std=c++11

# makefile targets
all : test_Gauss2.exe test_Composite.exe test_adapt.exe test_carbon.exe

test_Gauss2.exe : test_Gauss2.cpp composite_Gauss2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_Composite.exe : test_Composite.cpp composite_int.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_adapt.exe : test_adapt.cpp adaptive_int.cpp composite_int.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_carbon.exe : adaptive_int.cpp composite_int.cpp carbon.cpp matrix.cpp test_carbon.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
