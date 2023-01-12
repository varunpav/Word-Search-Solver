#Varun Pavuloori, uja2wd, uja2wd@virginia.edu, 10.13.22
#Makefile for Lab06 Prelab, HashTables

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

a.out: hashTable.o timer.o wordPuzzle.o 
	$(CXX) $(DEBUG) hashTable.o timer.o wordPuzzle.o -o a.out

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h

.PHONY: clean
clean:
	-rm -f *.o a.out
