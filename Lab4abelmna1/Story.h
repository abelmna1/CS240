#ifndef _Story_H_
#define _Story_H_

class Story;

#include "Sentence.h"
#include "Story.h"
#include "Paragraph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <string>
using namespace std;
class Story{

   private: 
     Paragraph * head;
     bool is_piggy;
   public:
     Story();
     ~Story();
     Story(const Story &w1);
     void show();
 
     void setHead(Paragraph *);
     Paragraph * getHead();

     bool fileExists(string);
     Story operator+(const Story& first_story) const;
     Story operator+(const Paragraph& a_paragraph) const;
     Story operator++(int i);
     Story operator--(int i);
     Story& operator+(int i);
     Story& operator++();
     Story& operator--();
     Story& operator=(const Story& a_story);
     friend ostream& operator<<(ostream& out, const Story& a_story);
     Story rest();
     Paragraph first();
     Story(string file_name);
     void save(string); 
};

#endif
