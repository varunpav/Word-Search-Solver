//Varun Pavuloori, uja2wd, uja2wd@virginia.edu, 10.27.22
//hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>
using namespace std;

class hashTable {
 public:
  hashTable();
  hashTable(int n);
  //prime of (2*dictionary) get next prime
  ~hashTable();
  //hashtable as a vector of strings
  void insert(string x);
  //hash x, look at index and add, until
  bool contains(string x);
  //hash x, lookup in the hashtable and see if they are the same, else look untiblank or the word
  vector<string> table;

 private:
  
  int hash(string x);
  //sum all of the chars then mod size of table
  int size;
  
  //checkprime
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
 
};

#endif
