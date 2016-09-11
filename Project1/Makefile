CXX=g++

proj1_a.exe : proj1_a.o Nest.o matrix.cpp
	$(CXX) $^ -o $@

proj1_b.exe : proj1_b.o matrix.cpp
	$(CXX) $^ -o $@

clean :
	rm -f *.o
	rm -f *.txt

rebuild :
	rm -f *.o
	rm -f *.txt
	make proj1_a.exe
	make proj1_b.exe

uninstall :
	rm -f *.o
	rm -f *.txt
	rm -f *.exe
