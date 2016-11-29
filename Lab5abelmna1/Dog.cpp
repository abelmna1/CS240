#include "Dog.h"
#include <iostream>
#include <vector>
#include <boost/format.hpp>
using namespace std;

Dog::Dog(){
 puppy = 0;
 
}

Dog::~Dog(){
}

Dog::Dog(const Dog &d1){
   puppy = d1.puppy;
}

Dog::Dog(double p){
  puppy = p;
}



double Dog::getPuppy(){
 return puppy;
}

Dog &Dog::operator=(const Dog &d1){
  puppy = d1.puppy;
  return (*this);
} 

Dog * Dog::operator+(const Dog &d1) const{
   Dog  * newDog;
   double newPuppy;
   newPuppy = puppy + d1.puppy;
   newDog = new Dog(newPuppy);
   return newDog;
}

ostream &operator<<(ostream& out, const Dog& d){
  out << boost::format("%1$.1f") % d.puppy;
  return out;
}

bool operator<(const Dog &d1, const Dog &d2){
  return (d1.puppy < d2.puppy);
}

bool operator>(const Dog &d1, const Dog &d2){
  return (d1.puppy > d2.puppy);
} 


void Dog::setPuppy(double d){
 puppy = d;
}

void Dog::printPuppy(){
  cout << "Puppy's number: " << puppy << endl;
}


