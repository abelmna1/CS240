#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;                       
} 

// Iterative Insertion Sort
void Sorter::insertionSortI() {
   unsigned int i,j;
   for(i = 1; i < numElements; i++){
     int currentNumToInsert = array[i];
     j = i;
     while((j > 0) && (array[j-1] > currentNumToInsert)){
        array[j] = array[j-1];
        j--;
     }
     array[j] = currentNumToInsert;
   }   


//cout << "Sorter::insertionSortI() not implemented yet." << endl << endl;
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
   unsigned int i,j, min;
   

   for(i = 0; i < numElements; i++){
      min = i;
     for(j = i; j < numElements; j++){
       if(array[min] > array[j]){
         min = j;
       }
     }
    swap(i, min);
   }
//cout << "Sorter::selectionSortI() not implemented yet." << endl << endl;
}

void Sorter::selectionHelper1(unsigned int i){
  unsigned int j, min;
  if(i < numElements){
   min = i;
   j = i;   
   selectionHelper2(j,  min);
    swap(i, min);
    selectionHelper1(i+1);
  }
// if(i < numElements)  selectionHelper1(++i);
}


void Sorter::selectionHelper2(unsigned int j, unsigned int& min){
  if(array[min] > array[j]){
    min = j;   
  }
  
    if(j < numElements) selectionHelper2(++j, min);
  
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
  unsigned int i,j;
 // i = 0;
  for(i = 0; i < numElements; i++){
    for(j = 0; j < numElements - 1; j++){
      if(array[j] > array[j+1]){
        swap(j+1, j);
      }
   }
  }
//cout << "Sorter::bubbleSortI() not implemented yet." << endl << endl;
}

void Sorter::bubbleHelper1(unsigned int i){

   unsigned int j;
  
 // for(i = 0; i < numElements; i++){
   /* for(j = 0; j < numElements - 1; j++){
      if(array[j] > array[j+1]){
        swap(j+1, j);
      }
    } */
    j = 0;
    bubbleHelper2(j);


 // }
 if(i < numElements) bubbleHelper1(++i);
}

void Sorter::bubbleHelper2(unsigned int j){
  if(array[j] > array[j+1]){
    swap(j+1, j);  
  }
  if(j < numElements - 1) bubbleHelper2(++j);
}

void Sorter::insertionHelper1(unsigned int i){
       
       //int currentNumToInsert = array[i];
       int j = i;
      insertionHelper2(j);   


 /*while((j > 0) && (array[j-1] > currentNumToInsert)){
        array[j] = array[j-1];
        j--;
     }*/
     //array[j] = currentNumToInsert;
     if( i < numElements) insertionHelper1(++i);
     
  
}

void Sorter::insertionHelper2(unsigned int j){
    
    if((j <= 0) || (array[j-1] < array[j])){
        return;
    }
    else{
      swap(j, j-1);
      insertionHelper2(--j);
    }
}
     
// Recursive Insertion Sort
void Sorter::insertionSortR() {
  
   if(numElements == 1) return; 
   insertionHelper1(1);   
   
      
  
}
 
// Recursive Selection Sort

void Sorter::selectionSortR() {
   if(numElements == 1) return;
   selectionHelper1(0);
  


}
	
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
  if(numElements == 1) return;
  bubbleHelper1(0); 
}




