#ifndef _TSorter_H_
#define _TSorter_H_


#include <iostream>
#include <vector>

using namespace std;

#include <cstdlib>

template<typename Item>

class TSorter {
   private:
      int *array;
      vector<Item> vect; 
      unsigned int numElements;
      unsigned int capacity;

      void swap(typename vector<Item>::iterator, typename vector<Item>::iterator);
      void swap(unsigned int, unsigned int); 

  public:
      TSorter();
      TSorter(unsigned int initialCapacity);
      ~TSorter();

      void clear(); 
      bool insert(Item value); 

      // Make sure the array contains at least newCapacity elements.
      // If not, grow it to that size and copy in old values
      unsigned int makeSpace(unsigned int newCapacity); 

      // Show the first n elements, k per line using << 
      void show(unsigned int n, unsigned int k); 
      void print();
      void printSize();
      // "Shuffle" the array elements
      void shuffle(); 

      // These are the functions you should implement for Lab 5
      // You should keep these interfaces the same, but you may add
      // other "helper" functions if necessary.
      void insertionSortI();
      void selectionSortI();
      void bubbleSortI();     
      void insertionSortR();
      void selectionHelper1(typename vector<Item>::iterator ); 
     void  selectionHelper2(typename vector<Item>::iterator, typename vector<Item>::iterator& );
      void selectionSortR();	
      void bubbleSortR();
      void bubbleHelper1(typename vector<Item>::iterator); 
      void bubbleHelper2(typename vector<Item>::iterator);
      void insertionHelper1(typename vector<Item>::iterator);	
      void insertionHelper2(typename vector<Item>::iterator);
};

#endif



