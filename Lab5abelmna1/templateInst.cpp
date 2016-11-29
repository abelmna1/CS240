#include <string>
#include "TSorter.cpp"
#include "Dog.h"
#include "Dog.cpp"
using namespace std;

template class TSorter<int>;
template class TSorter<string>;
template class TSorter<Dog>;

