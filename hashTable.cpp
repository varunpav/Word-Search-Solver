//Varun Pavuloori, uja2wd, uja2wd@virginia.edu, 10.27.22
//hashTable.cpp

#include "hashTable.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

hashTable::hashTable(){
}

hashTable::hashTable(int n){
  size = n;
  table.resize(getNextPrime(2*n));

  int thirtysevenpow [25];
  for(int g=0; g<25; g++){
    thirtysevenpow[g]=pow(37, g);
  }
  
}

hashTable::~hashTable(){
  // delete table;
}

void hashTable::insert(string x){
  int xhash = hash(x);
  bool insertion = false;
  if (table[xhash]=="")
    table[xhash]=x;
  else{
    for (int i=xhash; i<size; i++){
      if (table[i]==""){
	table[i]=x;
	insertion = true;
	break;
      }
    }
    for (int g=0; g<xhash; g++){
      if (insertion == true)
	break;
      else if(table[g]=="")
	table[g]=x;
    }
  }
}

bool hashTable::contains(string x){
  int xhash = hash(x);
  if (table[xhash]==x)
    return true;
  else{
    for (int i = xhash; i<size; i++){
      if (table[i]==x)
	return true;
      if (table[i]=="")
	return false;
      if (i==size)
	break;
    }
    for (int g = 0; g<xhash; g++){
      if (table[g]==x)
	return true;
      if (table[g]=="" || g==xhash)
	return false;
    }
  }
  return false;
}

int hashTable::hash(string x){
  unsigned long hashval = 0; 
  for (int i=0; i<x.length(); i++){
    hashval+=x[i]*pow(37, i);
  }
  return hashval % size;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}



