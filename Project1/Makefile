CXX=g++

proj1 : proj1_a.o proj1_b.o Nest.o matrix.cpp
	$(CXX) proj1_a.o Nest.o matrix.cpp -o proj1_a.exe
	$(CXX) proj1_b.o -o proj1_b.exe

proj1_a.exe : proj1_a.o Nest.o matrix.cpp
	$(CXX) $^ -o $@

proj1_b.exe : proj1_b.o
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
