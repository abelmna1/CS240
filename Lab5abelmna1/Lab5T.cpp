#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include "TSorter.h"
#include "Dog.h"

#include <vector>
#include <algorithm>

#define DEFAULT_NUMVALUES 10
#define MAX_NUMVALUES 1000
#define MIN_NUMVALUES 1
#define STRING_LENGTH 4;

static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

 char genRandom(){
  unsigned int strLength = sizeof(letters) - 1;
  return letters[rand() % strLength];

}

int main (int argc, char **argv) {
 
  unsigned int numValues = DEFAULT_NUMVALUES;
   int value;

   if (argc > 1)
      numValues = atoi(argv[1]);
   if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
      cerr << "Specify numValues in the range [" << MIN_NUMVALUES;
      cerr << ", " << MAX_NUMVALUES << endl;
      cerr << "\nUsage: " << argv[0] << " {numValues}" << endl;
   }
   if (argc > 2)
      cerr << "Ignoring extra command line arguments." << endl;

   cout << endl << "Generating " << numValues << " values for sorting." << endl;
   TSorter<int> s;
   s.makeSpace(numValues);
   //s.printSize();  
   srand(time(NULL)); // use this line for pseudo-random numbers
   // srand(23);      // use this line for deterministic "random" numbers

   for (unsigned int i=0; i < numValues; i++) {
      value = rand() % 100;
      s.insert(value);
   } 

   cout << "initial vector: ";
   s.show(25,10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortI();
   cout << "After iterative Selection Sort:";
   s.show(25,10);

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.insertionSortI();
   cout << "After iterative Insertion Sort:";
   s.show(25,10);

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.insertionSortR();
   cout << "After recursive Insertion Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortR();
   cout << "After recursive Selection Sort:";
   s.show(25, 10); 
  
   
    s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

  
  
  unsigned int i;
 
  

  
   //unsigned int numValues = DEFAULT_NUMVALUES;
   unsigned int stringSize = STRING_LENGTH;
   string str;

   if (argc > 1)
      numValues = atoi(argv[1]);
   if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
      cerr << "Specify numValues in the range [" << MIN_NUMVALUES;
      cerr << ", " << MAX_NUMVALUES << endl;
      cerr << "\nUsage: " << argv[0] << " {numValues}" << endl;
   }
   if (argc > 2)
      cerr << "Ignoring extra command line arguments." << endl;

   cout << endl << "Generating " << numValues << " values for sorting." << endl;
   TSorter<string> ts2;
   ts2.makeSpace(numValues);

   srand(time(NULL)); // use this line for pseudo-random numbers
   // srand(23);      // use this line for deterministic "random" numbers

   

   for(i = 0; i < numValues; i++){
   for(unsigned int j = 0; j < stringSize; j++)
       str += genRandom();
   ts2.insert(str);
   str = "";
   }



  
 cout << "Initial vector: ";
   ts2.show(25, 10); 

   ts2.insertionSortI();
   cout << "After iterative Insertion Sort:";
   ts2.show(25,10);

   ts2.shuffle(); 
   cout << "Shuffled: "; 
   ts2.show(25, 10); 

   ts2.selectionSortI();
   cout << "After iterative Selection Sort:";
   ts2.show(25,10);

   ts2.shuffle(); 
   cout << "Shuffled: "; 
   ts2.show(25, 10); 

   ts2.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   ts2.show(25, 10); 

   ts2.shuffle(); 
   cout << "Shuffled: "; 
   ts2.show(25, 10); 

   ts2.insertionSortR();
   cout << "After recursive Insertion Sort:";
   //cout << "entered show" << endl;
   ts2.show(25, 10);  

   ts2.shuffle(); 
   cout << "Shuffled: "; 
   ts2.show(25, 10); 

   ts2.selectionSortR();
   cout << "After recursive Selection Sort:";
   ts2.show(25, 10); 

   ts2.shuffle(); 
   cout << "Shuffled: "; 
   ts2.show(25, 10); 

   ts2.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   ts2.show(25, 10); 

   ts2.shuffle(); 
   cout << "Shuffled: "; 
   ts2.show(25, 10); 

   TSorter<Dog> ts5;
   ts5.makeSpace(10);
   
   Dog d1(1.0);
   Dog d2(2.0);
   Dog d3(3.0);
   Dog d4(4.0);
   Dog d5(5.0);
   Dog d6(6.0);
   Dog d7(7.0);
   Dog d8(8.0);
   Dog d9(9.0);
   Dog d10(10.0);
 
   ts5.insert(d1);
   ts5.insert(d2);
   ts5.insert(d3);
   ts5.insert(d4);
   ts5.insert(d5);
   ts5.insert(d6);
   ts5.insert(d7);
   ts5.insert(d8);
   ts5.insert(d9);
   ts5.insert(d10);
   
   cout << "Initial vector: ";
   ts5.show(25, 10); 

   cout << "After shuffling: ";
   ts5.shuffle();
   ts5.show(25,10);
   
   

   ts5.insertionSortI();
   cout << "After iterative Insertion Sort:";
   ts5.show(25,10);

   ts5.shuffle(); 
   cout << "Shuffled: "; 
   ts5.show(25, 10); 

   ts5.selectionSortI();
   cout << "After iterative Selection Sort:";
   ts5.show(25,10);

   ts5.shuffle(); 
   cout << "Shuffled: "; 
   ts5.show(25, 10); 

   ts5.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   ts5.show(25, 10); 

   ts5.shuffle(); 
   cout << "Shuffled: "; 
   ts5.show(25, 10); 

   ts5.insertionSortR();
   cout << "After recursive Insertion Sort:";
   //cout << "entered show" << endl;
   ts5.show(25, 10);  

   ts5.shuffle(); 
   cout << "Shuffled: "; 
   ts5.show(25, 10); 

   ts5.selectionSortR();
   cout << "After recursive Selection Sort:";
   ts5.show(25, 10); 

   ts5.shuffle(); 
   cout << "Shuffled: "; 
   ts5.show(25, 10); 

   ts5.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   ts5.show(25, 10); 

   ts5.shuffle(); 
   cout << "Shuffled: "; 
   ts5.show(25, 10);
   
   
  

  
 

  
   
   


   



   return 0;
}
