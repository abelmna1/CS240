#include "Word.h"
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;




Word::Word(){
  /*cout << "Entering function Word::Word()" << endl;
  cout << "Leaving function Word::Word()" << endl; */
  a_word = "";
  is_piggy = false; next = NULL; before_piggy = "";
 }

Word::Word(string str){
   /*cout << "Entering function Word::Word(str)" << endl;
  cout << "Leaving function Word::Word(str)" << endl; */
  a_word = str;
  is_piggy = false; next = NULL; before_piggy = "";
}

void Word::show(){
 /*cout << "Entering function Word::show()" << endl;
 cout << "Show() will print out WORD'S data members in a neat format." << endl;
 cout << "Leaving function Word::show()" << endl; */
}

Word::~Word(){
  //cout << "Entering function Word::~Word()" << endl;
  //delete next;
  //cout << "Leaving function Word::~Word()" << endl; 
}

Word::Word(const Word &w1){
  //cout << "Entering function Word::copyConstructor" << endl;
  
  (*this).is_piggy = w1.is_piggy;
  (*this).a_word =  w1.a_word;
  (*this).before_piggy = w1.before_piggy;
 // cout << "Leaving function Word::copyConstructor" << endl;
} 

Sentence Word::operator+(const Sentence& a_sentence) const{
   // cout << "Entering function Word::Operator+Sentence()" << endl;
    /*Sentence new_sentence;
   // Sentence old_sentence = new Sentence();
    Sentence old_sentence = a_sentence;
    Word * new_word = new Word(*this);
    Word * node_ptr = new_word;
    new_sentence.setHead(node_ptr);
    Word * temp = old_sentence.getHead();
    Word * temp2 = new Word(a_sentence.getHead()); 
    
    while(temp != NULL){
       Word * node = new Word(*temp);
       
       node_ptr->next = node;
       node_ptr = node;
       
       temp = temp->next;
    }
    node_ptr->next = NULL;
     
    
    new_sentence.setNext(NULL);  */   

    Sentence copy_s(a_sentence);
  if(a_word == "") return copy_s;
  if(copy_s.getHead() == NULL) copy_s.setHead(new Word(*this)); //set the 1st word as beginning of sentence if sent is    NULL
  else{ 
    Sentence * snode = &copy_s;
    Word * new_word = new Word(*this);
   // Word * s_head = copy_s.getHead();
    //Word * wnode = new_word;
    new_word->setNext(copy_s.getHead());
    snode->setHead(new_word);
  }  
    
  //  cout << "Leaving function Word::Operator+Sentence()" << endl;
    return copy_s;

}

Sentence Word::operator+(const Word& a_word) const{
 //  cout << "Entering function Word::Operator+Word()" << endl;
   /*Sentence sent;
   WordNode *node1 = new WordNode(); WordNode *node2 = new WordNode();
   sent.setHead(node1);
   node1->word = new Word(*this);
   node1->next = node2;
   node2->word = new Word(a_word);
   node2->next = NULL; */

   Sentence sent;
   Word * node1 = new Word(*this);
   Word * node2 = new Word(a_word);
   sent.setHead(node1);
   node1->next = node2;
   node2->next = NULL;
   sent.setNext(NULL);
   sent.setPunct('.');
 //  cout << "Leaving function Word::Operator+Word()" << endl;

   return sent;
}

Word Word::operator++(int i){
  // cout << "Entering function Word::Operator++&Word" << endl;
   Word w(a_word);
   int j; 
   for(j = 0; j < a_word.length(); j++){
     a_word.at(j) = toupper(a_word.at(j));
   }
  
   
 //  cout << "Leaving function Word::Operator++&Word" << endl;
   return w;
}

ostream &operator<<(ostream& out, const Word& w){
  //   cout << "Entering function Word::Operator<<Word" << endl;
   int j;
   for(j = 0; j < w.a_word.size(); j++)
      out << w.a_word.at(j);
   
 //  cout << "Leaving function Word::Operator<<Word" << endl;
   return out;
} 


Word Word::operator--(int i){
 //  cout << "Entering function Word::Operator--&Word" << endl;
   Word w(a_word);
   int j;
    for(j = 0; j < a_word.length(); j++){
     a_word.at(j) = tolower(a_word.at(j));
   }
   
 //  cout << "Leaving function Word::Operator--&Word" << endl;
   return w;
}

Word &Word::operator+(int i){
 //  cout << "Entering function Word::operator+&Word" << endl;
   if(i == 1){
     a_word.at(0) = toupper(a_word.at(0));
   }
  //   cout << "Leaving function Word::operator+&Word" << endl;
   return (*this);
}

Word &Word::operator++(){
  // cout << "Entering function Word::operator++" << endl;
 
 bool is_first_word = false;
 if(!is_piggy){
   before_piggy = a_word;
   if(a_word.at(0) == 'A' || a_word.at(0) == 'E' || a_word.at(0) == 'I' || a_word.at(0) == 'O' || a_word.at(0) == 'U' || a_word.at(0) == 'B' || a_word.at(0) == 'C' ||
      a_word.at(0) == 'D' || a_word.at(0) == 'F' || a_word.at(0) == 'G' || a_word.at(0) == 'H' || a_word.at(0) == 'J' || a_word.at(0) == 'K' || a_word.at(0) == 'L' ||
      a_word.at(0) == 'M' || a_word.at(0) == 'N' || a_word.at(0) == 'P' || a_word.at(0) == 'Q' || a_word.at(0) == 'R' || a_word.at(0) == 'S' || a_word.at(0) == 'T' ||
      a_word.at(0) == 'V' || a_word.at(0) == 'W' || a_word.at(0) == 'X' || a_word.at(0) == 'Y' || a_word.at(0) == 'Z' ){
      is_first_word = true;
   }
   (*this)--;

   if(a_word.at(0) != 'a' && a_word.at(0) != 'e' && a_word.at(0) != 'i' && a_word.at(0) != 'o' && a_word.at(0) != 'u'){
       int j; int i = 0; bool vowel_found = false; string sub_str;
      for(j = 1; j < a_word.length(); j++){
        if(!vowel_found){
          if(a_word.at(j) == 'a' || a_word.at(j) == 'e' || a_word.at(j) == 'i' || a_word.at(j) == 'o' ||
             a_word.at(j) == 'u'){
                 vowel_found = true;
                 i = j;
                 sub_str = a_word.substr(0, i);
           }
        }
      }
      if(vowel_found){
         a_word.append(sub_str);
         a_word.erase(0, i);
         a_word.append("ay");
         if(is_first_word) (*this) + 1;
         
      }
  }
  else{
    a_word.append("way");
  }
  is_piggy = true;
 }
  return (*this);
}

Word &Word::operator--(){
  // cout << "Entering function Word::operator--()" << endl;
   if(is_piggy){
     a_word = before_piggy;
     is_piggy = false;
     
      
   }
 //  cout << "Leaving function Word::operator--()" << endl;
   return (*this);
}

Word &Word::operator=(const Word& s1){
 //  cout << "Entering function Word::operator=()" << endl;
   is_piggy = s1.is_piggy;
   a_word = s1.a_word;
   next = s1.next;
   

 // cout << "Leaving function Word::operator=()" << endl;
  return (*this);
}

string Word::getString(){
   return a_word;
}

Word * Word::getNext(){
   //cout << "Entering Word::getNext()" << endl;
   return next;
   //cout << "Entering Word::getNext()" << endl;
}

void Word::setNext(Word * ptr){
  // cout << "Entering Word::setNext()" << endl;
   next = ptr;
  // cout << "Leaving Word::setNext()" << endl;
}

string Word::getBeforePiggy(){
   return before_piggy;
}
