#ifndef _Word_H_
#define _Word_H_

class Word;

#include "Sentence.h"
#include "Story.h"
#include <iostream>
using namespace std;
class Word{
  private:
    string a_word;
    bool is_piggy; 
    Word * next;
    string before_piggy;

   public:
     Word();
     Word(string str);
     ~Word();
     Word(const Word &w1);
     void show();
     Sentence operator+(const Sentence& a_sentence) const;
     Sentence operator+(const Word& a_word) const;
     Word operator++(int i);
     friend ostream& operator<<(ostream &out, const Word &a_word);
     Word operator--(int i);
     Word &operator+(int i);
     Word &operator++();   /* ======>> PREFIX */
     Word &operator--(); /* =====>> PREFIX */
     Word &operator=(const Word& a_word); 
     string getString();
     Word * getNext();
     void setNext(Word * ptr);
     string getBeforePiggy();
};

#endif
