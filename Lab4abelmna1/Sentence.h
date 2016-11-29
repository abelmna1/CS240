#ifndef _Sentence_H_
#define _Sentence_H_




class Sentence;
class WordNode;

#include "Paragraph.h"
#include "Sentence.h"
#include "Story.h"
#include "Word.h"
#include <iostream>
using namespace std;
/*class WordNode{
   public:
    Word *word;
    WordNode * next;
   }; */




class Sentence{

 private:
      /*WordNode * head; */
     bool is_piggy;
     Sentence * next;
     Word * head;
     char punct;
   public:
     Sentence();
     ~Sentence();
     Sentence(string value);
    /* void setHead(WordNode * ptr);
     WordNode * getHead(); */
     
     void setHead(Word * ptr);
     Word * getHead();
     void setNext(Sentence * ptr);     
     Sentence * getNext();
     char getPunct();
     void setPunct(char);

     Sentence(const Sentence &w1);
     Paragraph operator+(const Paragraph& a_paragraph) const; 
     Paragraph operator+(const Sentence& a_sentence) const;   
     Sentence operator+(const Word& a_word) const;
     Sentence operator++(int i);
     Sentence operator--(int i); 
     Sentence &operator+(int i);
     void show();
     Sentence &operator++();
     Sentence &operator--();
     Word first();
     Sentence rest();
     Sentence &operator=(const Sentence& a_sentence);
     friend ostream& operator<<(ostream& out, const Sentence& s);

    



   
};

#endif
