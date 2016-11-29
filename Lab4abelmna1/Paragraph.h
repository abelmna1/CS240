#ifndef _Paragraph_H_
#define _Paragraph_H_

class Paragraph;

#include "Sentence.h"
#include "Story.h"
#include "Word.h"
#include <iostream>
using namespace std;
class Paragraph{
   
  private:
    Sentence * head;
    Paragraph * next;
    
    bool is_piggy;
  public:
     Paragraph();
     ~Paragraph();
     Paragraph(string value);
     Paragraph(const Paragraph &w1);
     void show();

     void setHead(Sentence * ptr);
     void setNext(Paragraph * ptr);
     Sentence * getHead();
     Paragraph * getNext();
     

     Story operator+(const Story& a_story) const;
     Paragraph operator+(const Paragraph& a_paragraph) const;
     Paragraph operator+(const Sentence& a_sentence) const;
     Paragraph operator++(int i);
     Paragraph operator--(int i);
     Paragraph& operator+(int i);
     Paragraph& operator++();
     Paragraph& operator--();
     Sentence first();
     Paragraph rest();
     Paragraph& operator=(const Paragraph& a_paragraph);
     friend ostream& operator<<(ostream& out, const Paragraph& paragraph);   
};

#endif
