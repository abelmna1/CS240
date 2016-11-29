#include "TSorter.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
//#include "Dog.h"
using namespace std;




template <typename Item>
void TSorter<Item>::swap(typename vector<Item>::iterator iter1, typename vector<Item>::iterator iter2) {

   Item tmp; 
   tmp = (*iter1); 
   (*iter1) = (*iter2);
   (*iter2) = tmp; 
   return; 
}


template <typename Item>
TSorter<Item>::TSorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;
  
    
}

template <typename Item>
TSorter<Item>::TSorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
}

template <typename Item>
unsigned int TSorter<Item>::makeSpace(unsigned int newCapacity) {
   capacity = newCapacity;





 /* vector<Item> old;  //int *old;
 typename  vector<Item>::iterator iter1;
  
   
   unsigned int i;
  if (newCapacity > capacity) {
     for(iter1 = vect.begin(); iter1 != vect.end(); iter1++){ //old = array; 
     old.push_back(*iter1);
   }                
   vect = vector<Item>(newCapacity); 
   iter1 = old.begin();
   typename vector<Item>::iterator iter2;
     for(iter2 = vect.begin(); iter2 != vect.end(); iter2++, iter1++)
        *iter2 = *iter1; 
    
    capacity = newCapacity;
   
  } */

   return capacity;
}

template <typename Item>
void TSorter<Item>::clear() {
   numElements = 0;
   return; 
}

template <typename Item>
bool TSorter<Item>::insert(Item element) {
   //element = new Item();
   if (numElements >= capacity) 
      return false;
   vect.push_back(element); 
    //numElements++;         //array[numElements++] = element;  
  
   return true;
}

template <typename Item>
TSorter<Item>::~TSorter() {
  

  /*if (vect.size() != 0) {       //if(array)
      delete vect;                     // delete array; 
      numElements = 0; 
   } */
}

template <typename Item>
// Shuffle array elements
void TSorter<Item>::shuffle() {
   
   typename vector<Item>::iterator iter;
 
   random_shuffle(vect.begin(), vect.end());  //can we use built-in functions?  
}

template <typename Item>
// Show the first n elements, k per line, using << 
void TSorter<Item>::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << vect[i] << " "; 
   }
   cout << endl << endl;                       
} 

template <typename Item>
void TSorter<Item>::print(){
  typename vector<Item>::iterator iter;
  for(iter = vect.begin(); iter != vect.end(); iter++){
    cout << *iter << " ";
  }
  cout << endl;

}

template <typename Item>
void TSorter<Item>::printSize(){
  cout << "Vector size: " << numElements << endl;
}



template <typename Item>
// Iterative Insertion Sort
void TSorter<Item>::insertionSortI() {
   //unsigned int i,j;
   typename vector<Item>::iterator iter1;
   typename vector<Item>::iterator iter2;
   typename vector<Item>::iterator iter3;
   
  // iter1 = vect.begin();
   //cout << "iter1: " << *iter1 << endl;
   //iter1++;
  // cout << "iter1++: " << *iter1 << endl;
   for(iter1 = vect.begin() + 1; iter1 < vect.end(); iter1++){
     Item currentItemToInsert = (*iter1);
     iter2 = iter1;
     //cout << "iter2: " << *iter2 << endl;
      iter3 = iter2-1;
     //cout << "iter3: " << *iter3 << endl;
     while((iter2 != vect.begin()) && (*(iter3) > currentItemToInsert)){
         
         
         *(iter2) = *(iter3);
         //cout << "--iter2: " << *iter2 << endl;
          iter2--;
          iter3--;
     }
     *iter2 = currentItemToInsert;
   }    
}

// Iterative Selection Sort

template <typename Item>
void TSorter<Item>::selectionSortI() {
  // unsigned int i,j, min;
   typename vector<Item>::iterator iter1;
   typename vector<Item>::iterator iter2;
   typename vector<Item>::iterator min;
   

   for(iter1 = vect.begin(); iter1 < vect.end(); iter1++){
      min = iter1;
      for(iter2 = iter1; iter2 < vect.end(); iter2++){
         if((*min) > (*iter2)){
             min = iter2;
         } 
      }
      swap(iter1, min);
   } 
}

template <typename Item>
void TSorter<Item>::selectionHelper1(typename vector<Item>::iterator iter1){
  typename vector<Item>::iterator iter2, min;
   min = iter1;
   iter2 = iter1;   
/*   for(j = i; j < numElements; j++){
       if(array[min] > array[j]){
         min = j;
       }
    }*/
    selectionHelper2(iter2,  min);
    swap(iter1, min);
    iter1++;
 if(iter1 < vect.end())  selectionHelper1(iter1);
}

template <typename Item>
void TSorter<Item>::selectionHelper2(typename vector<Item>::iterator iter2, typename vector<Item>::iterator& min){
  if((*min) > (*iter2)){
    min = iter2;   
  }
   iter2++;
  
    if(iter2 < vect.end()) selectionHelper2(iter2, min);
  
}

// Iterative Bubble Sort
template <typename Item>
void TSorter<Item>::bubbleSortI() {
 // unsigned int i,j;
 // i = 0;
  typename vector<Item>::iterator iter1;
  typename vector<Item>::iterator iter2;
  typename vector<Item>::iterator iter3;
  typename vector<Item>::iterator iter4;
  
  /*for(iter3 = vect.begin(); iter3 != vect.end() - 1; iter3++){
     iter4 = iter3;
     
  }*/
  iter4 = vect.end()-1;

  //cout << "iter4: " << *iter4 << endl;  //iter4 pointing to to numElements - 1
 // cout << "iter3: " << *iter3 << endl;

  for(iter1 = vect.begin(); iter1 < vect.end(); iter1++){
     // cout << "iter1: " << *iter1 << endl;
    for(iter2 = vect.begin(); iter2 < iter4; iter2++){
       //iter3 = iter2 + 1;
    //   cout << "iter2: " << *iter2 << endl;
     //  cout << "iter3: " << *iter3 << endl;
       if(*iter2 > *(iter2+1)) swap((iter2+1), iter2);   
    }
  }
}

template <typename Item>
void TSorter<Item>::bubbleHelper1(typename vector<Item>::iterator iter1){
   typename vector<Item>::iterator iter2;
   iter2 = vect.begin();
  
 // for(i = 0; i < numElements; i++){
   /* for(j = 0; j < numElements - 1; j++){
      if(array[j] > array[j+1]){
        swap(j+1, j);
      }
    } */
    
    bubbleHelper2(iter2);
    iter1++;


 // }
 if(iter1 < vect.end()) bubbleHelper1(iter1);
}

template <typename Item>
void TSorter<Item>::bubbleHelper2(typename vector<Item>::iterator iter2){
  if((*iter2) > *(iter2+1)){
    swap((iter2+1), iter2);  
  }
  
  typename vector<Item>::iterator cond;
  cond = vect.end()-1;
   iter2++;
  
  if(iter2 < cond) bubbleHelper2(iter2);
}

template <typename Item>
void TSorter<Item>::insertionHelper1(typename vector<Item>::iterator iter1){
       
       
       //int currentNumToInsert = array[i];
       typename vector<Item>::iterator iter2, iter3;
       iter2 = iter1;
       
      insertionHelper2(iter2);  
      


 /*while((j > 0) && (array[j-1] > currentNumToInsert)){
        array[j] = array[j-1];
        j--;
     }*/
     //array[j] = currentNumToInsert;
     //*iter2 = *iter1;
     iter1++;
     if( iter1 != vect.end()) insertionHelper1(iter1);
     
  
}

template <typename Item>
void TSorter<Item>::insertionHelper2(typename vector<Item>::iterator iter2){
    
    //typename vector<Item>::iterator iter3;
    //iter3 = iter2 - 1;
    //cout << "iter3: " << *iter3 << endl;
    
    if((iter2 != vect.begin()) && (*(iter2-1) > *iter2)) {
      //*(iter2) = *(iter2-1);
      swap(iter2, iter2-1);
      iter2--;
      insertionHelper2(iter2);
    }
}
     
// Recursive Insertion Sort
template <typename Item>
void TSorter<Item>::insertionSortR() {
   
  
   if(numElements == 1) return; 
   typename vector<Item>::iterator iter1;
   iter1 = vect.begin() + 1;
   
   //cout << "iter1: " << *iter1 << endl << endl;
   insertionHelper1(iter1);   
   
      
   //cout << "Sorter::insertionSortR() not implemented yet." << endl << endl;
}
 
// Recursive Selection Sort

template <typename Item>
void TSorter<Item>::selectionSortR() {
   if(numElements == 1) return;
   typename vector<Item>::iterator iter1;
   iter1 = vect.begin();
   selectionHelper1(iter1);
  

 
}
	
// Recursive Bubble Sort
template <typename Item>
void TSorter<Item>::bubbleSortR() {
  if(numElements == 1) return;
  typename vector<Item>::iterator iter1;
  iter1 = vect.begin();
  bubbleHelper1(iter1); 

 // cout << "Sorter::bubbleSortR() not implemented yet." << endl << endl;
}




