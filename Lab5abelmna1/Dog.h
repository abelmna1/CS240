#ifndef _DOG_H_
#define _DOG_H_




#include <iostream>
#include <vector>
using namespace std;

class Dog{

 private:
   double  puppy;
   
   
 public:
  Dog();
  ~Dog();
  Dog(const Dog&);
  Dog(double);
  Dog * operator+(const Dog&) const;
  Dog &operator=(const Dog&);
  friend ostream& operator<<(ostream &out, const Dog&);
  friend bool operator<(const Dog& d1, const Dog& d2);
  friend bool operator>(const Dog& d1, const Dog& d2);

  double getPuppy();
   void setPuppy(double);
   void printPuppy();
   
  
 };

#endif
 
