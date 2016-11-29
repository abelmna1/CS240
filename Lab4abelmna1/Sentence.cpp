#include "Sentence.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Sentence::Sentence(){
 /*cout << "Entering function Sentence::Sentence()" << endl;
 cout << "Leaving function Sentence::Sentence()" << endl; */
  head = NULL; next = NULL; is_piggy = false; punct = '\0';
 }

Sentence::Sentence(const Sentence &s1){
  //cout << "Entering function Sentence::copyConstructor" << endl;
    Word * last_word;
  if(s1.head == NULL) return;
  else{
    head = new Word(*s1.head);
    Word * temp = s1.head->getNext();
    Word * ntemp = head;
   
    while(temp != NULL){
      ntemp->setNext(new Word(*temp)); 
      temp = temp->getNext();
      ntemp = ntemp->getNext();
      if(temp->getNext() == NULL){
        last_word = temp;
      }
    }
    ntemp->setNext(NULL);
    next = NULL;
   }
  is_piggy = s1.is_piggy;
  //punct = ((*last_word).getString()).at(((*last_word).getString()).length() -1 ));
  
  
 // cout << "Leaving function Sentence::copyConstructor" << endl;
} 
  
Sentence::Sentence(string str){
 //cout << "Entering function Sentence::Sentence(value)" << endl;
 int i; int j; char c;
 if(str.length() == 0){
   head = NULL; next = NULL; is_piggy = false;
 }
 else{
   string word;
   istringstream stream(str);
   stream >> word;
   Word * newHead = new Word(word);
   Word * temp = newHead;
   Word * temp2 = newHead;
   head = newHead;
   while(stream >> word){
     if(word.at(word.length()-1) == '.' || word.at(word.length()-1) == '!' || word.at   (word.length()-1) == '?'){
        c = word.at(word.length() - 1);
        word = word.substr(0, word.length() - 1);  
        temp2->setNext(new Word(word));
        temp2 = temp2->getNext();
        punct = c;
        temp2->setNext(NULL);
     }
     else{
       temp2->setNext(new Word(word));
       temp2 = temp2->getNext();
     }
    next = NULL;
    is_piggy = false;   
  }
 }
     
     
 




//cout << "Leaving function Sentence::Sentence(value)" << endl;
}
  

void Sentence::show(){
 /*cout << "Entering function Sentence::show()" << endl;
 cout << "Show() will print out SENTENCE'S data members in a neat format." << endl;
 cout << "Leaving function Sentence::show()" << endl; */
}

Sentence::~Sentence(){
 //cout << "Entering function Sentence::~Sentence()" << endl;
   //Word * temp = head;
   Word * temp2 = head;
   Word * temp3 = head;
   while(temp2 != NULL){
     temp3 = temp3->getNext();
     delete (temp2);
     temp2 = temp3;
   } 



 //cout << "Leaving function Sentence::~Sentence()" << endl;
}

Paragraph Sentence::operator+(const Paragraph& a_paragraph) const{
  //cout << "Entering function Sentence::operator+Paragraph()" << endl;
  
  Paragraph copy_p(a_paragraph);
  Paragraph * pnode = &copy_p;
  Sentence * sent = new Sentence(*this);
  Sentence * p_head = copy_p.getHead();
  Sentence * snode = sent;
  snode->setNext(p_head);
  pnode->setHead(snode);
  
   
  //cout << "Leaving function Sentence::operator+Paragraph()" << endl;
  return copy_p;
}

Paragraph Sentence::operator+(const Sentence& a_sentence) const{
  //cout << "Entering function Sentence::operator+Sentence()" << endl;
  Paragraph new_paragraph;
  Sentence * sent1 = new Sentence(*this);
  Sentence * sent2 = new Sentence(a_sentence);
  if(sent1->getHead() == NULL || sent2->getHead() == NULL) return new_paragraph;
  new_paragraph.setHead(sent1);
  sent1->next = sent2;
  sent2->next = NULL;
  new_paragraph.setNext(NULL);
 // cout << "Leaving function Sentence::operator+Sentence()" << endl;
  return new_paragraph;
}

Sentence Sentence::operator+(const Word& a_word) const{
    //cout << "Entering function Sentence::operator+Word()" << endl;
   /* Sentence new_sentence;
    Word * temp = new Word(*head);
    Word * node_ptr = new Word(*head);
    Word final_word = a_word; //calls copy constructor
    
    Word * temp_node = &final_word;
    Word * final_node = new Word(*temp_node);
    
    Word * final_Node = new Word();
    new_sentence.setHead(node_ptr);
    if(temp == NULL) return new_sentence; //might have to add word anyway
    while(temp->getNext() != NULL){
       Word * node = new Word(*temp);
       node_ptr = node;
       temp = temp->getNext();
       node_ptr->setNext(temp);
    }
    Word * penum_word = new Word(*temp);
    node_ptr = penum_word;
    node_ptr->setNext(final_node);
    node_ptr = final_node;
    node_ptr->setNext(NULL);
    new_sentence.setNext(NULL); */

    Sentence s(*this);
    Word * temp = s.head;
    if(temp == NULL){
       s.head = new Word(a_word);
       (s.head)->setNext(NULL);
       s.setNext(NULL); //copy constructor might take care of this
       return s;
    }
    while(temp->getNext() != NULL){
       temp = temp->getNext();
    }
    temp->setNext(new Word(a_word)); 
    temp = temp->getNext();
    temp->setNext(NULL);
    
    s.setNext(NULL); //copy constructor might take care of this
    






    
    //cout << "Leaving function Sentence::operator+Word()" << endl;
    return s;
}

Sentence Sentence::operator++(int i){
    //cout << "Entering function Sentence::operator++&Sentence()" << endl;
   
   
   /* Sentence new_sentence; 
    Word * nodeptr = new Word(*head);
    new_sentence.setHead(nodeptr);
    Word * temp = new Word(*head);
    if(temp == NULL) return (*this);
    while(temp->getNext() != NULL){
       Word * node = new Word(*temp);
       (*node)++;
       nodeptr = node;
       temp = temp->getNext();
       nodeptr->setNext(temp);
    }
    Word * final_node = new Word(*temp);
    (*final_node)++;
    nodeptr = final_node;
    nodeptr->setNext(NULL);
    new_sentence.setNext(NULL);
    (*this) = new_sentence; */
    
    Sentence s(*this);
    Word * temp = head;
    if(temp == NULL) return s;
    while(temp != NULL){
      (*temp)++;
      temp = temp->getNext();
   }
     
   // cout << "Leaving function Sentence::operator++&Sentence()" << endl;
    return s;
}

Sentence Sentence::operator--(int i){
  //  cout << "Entering function Sentence::operator--&Sentence()" << endl;
  
   /* Sentence new_sentence;
    Word * nodeptr = new Word(*head);
    new_sentence.setHead(nodeptr);
    Word * temp = new Word(*head);
    if(temp == NULL) return (*this);
    while(temp->getNext() != NULL){
      Word * node = new Word(*temp);
      (*node)--; //make the word lower-case
      nodeptr = node;
      temp = temp->getNext();
      nodeptr->setNext(temp);
   }
   Word * final_node = new Word(*temp);
   (*final_node)--; //--> convert final word to lowercase
   nodeptr = final_node;
   nodeptr->setNext(NULL);
   new_sentence.setNext(NULL); 
   (*this) = new_sentence; */
   
   Sentence s(*this);
   
   Word * temp = head;
   
   
   if(temp == NULL){
     return s;
   }
   while(temp != NULL){
      (*temp)--;
      temp = temp->getNext();
   }
   
 
      
      
      
   // cout << "Leaving function Sentence::operator--&Sentence()" << endl;
    return s;
}

Sentence &Sentence::operator+(int i){
  //  cout << "Entering function Sentence::operator+(int i)" << endl;
    Word * temp = head;
    if(temp == NULL) return (*this);
    
    (*head) + i;
       
      
      //((head->word)->getString()).at(0) = toupper(((head->word)->getString()).at(0));   
    
  //  cout << "Leaving function Sentence::operator+(int i)" << endl;
    return (*this);
}

Sentence &Sentence::operator++(){
 //  cout << "Entering function Sentence::operator++()" << endl;
   //if(head == NULL) return (*this);
   if(!is_piggy){
     Word * temp = head;
     while(temp != NULL){
        ++(*temp);
        temp = temp->getNext();
     }
      is_piggy = true;
   }
 //  cout << "Leaving function Sentence::operator++()" << endl;
   return (*this);
}

Sentence &Sentence::operator--(){
  // cout << "Entering function Sentence::operator--()" << endl;
   if(head == NULL) return (*this);
   if(is_piggy){
      Word * temp = head;
      while(temp != NULL){
        --(*temp);
        temp = temp->getNext();
      }
    is_piggy = false;
        
     
   }
  // cout << "Leaving function Sentence::operator--()" << endl;
   return (*this);
}

ostream& operator<<(ostream& out, const Sentence& s){
  // cout << "Entering function Sentence::operator<<()" << endl;
  
   Word * temp = s.head;
   while(temp != NULL){
     if(temp->getNext() != NULL){
        out << (*temp).getString() << " ";
     }
     else{
        out << (*temp).getString() << s.punct << " ";
     }
     temp = temp->getNext();
   }
 //  cout << "Leaving function Sentence::operator<<()" << endl;
   return out;
}

Sentence &Sentence::operator=(const Sentence& a_sentence){
 //  cout << "Entering function Sentence::operator=()" << endl;
//   Word * temp = head;

   // Sentence sent(a_sentence);
   Sentence * sent = new Sentence(a_sentence);
  // Word * sent_head = sent.head;
   Word * temp2 = head;
   Word * temp3 = head;
   while(temp2 != NULL){
     temp3 = temp3->getNext();
     delete (temp2);
     temp2 = temp3;
   }
   
   /*Word * s_head = a_sentence.head;  ==> possible solution to MEMORY LEAK ******
   (*this).setHead(new Word(*s_head));
    s_head = s_head->getNext();
    Word * temp = head;
   while(s_head != NULL){
     temp->setNext(new Word(*s_head));
     s_head = s_head->getNext();
     temp = temp->getNext();
   }
   temp->setNext(NULL); */
   
     





   (*this).setHead(sent->getHead());
   
  // punct = a_sentence.punct;
   is_piggy = a_sentence.is_piggy;
   
   
 //  cout << "Leaving function Sentence::operator=()" << endl;
   return (*this);
}

Word Sentence::first(){
  // cout << "Entering function Sentence::first()" << endl;
   /*Word w;
   Word * temp = head;
   if(temp == NULL) return w;
   if(temp != NULL){
     Word word_copy = (*temp);  //calls copy constructor
     return word_copy; 
   }*/
  
   Word w;
   Word * temp = head;
   if(temp == NULL) return w;
   
   Word word(*temp);
   
   return word;   

 //  cout << "Leaving function Sentence::first()" << endl;
   
}

Sentence Sentence::rest(){
 // cout << "Entering function Sentence::rest()" << endl;
 
  Word * temp = head;
  Sentence null_sent;
  if(temp == NULL || temp->getNext() == NULL) return null_sent;

  temp = temp->getNext();  //NEW HEAD THAT WE WANT
  Sentence s;
  Word * snode = new Word(*temp);
  s.setHead(snode);
  if(temp->getNext() == NULL) snode->setNext(NULL);
  temp = temp->getNext();
  while(temp != NULL){
    snode->setNext(new Word(*temp));
    temp = temp->getNext();
    snode = snode->getNext();
  }
  
 // cout << "Leaving function Sentence::rest()" << endl;
  return s;
}

/*void Sentence::setHead(WordNode * ptr){
   cout << "Entering function Sentence::setHead()" << endl;
   head = ptr;
   cout << "Leaving function Sentence::setHead()" << endl;
}

WordNode * Sentence::getHead(){
   cout << "Entering function Sentence::getHead()" << endl;
   cout << "Entering function Sentence::getHead()" << endl;

   return head;
} */

void Sentence::setHead(Word * ptr){
 //  cout << "Entering function Sentence::getHead()" << endl;
   head = ptr;
  // cout << "Entering function Sentence::getHead()" << endl;
}

Word * Sentence::getHead(){
  //  cout << "Entering function Sentence::getHead()" << endl;
  // cout << "Leaving function Sentence::getHead()" << endl;
   return head;
}

void Sentence::setNext(Sentence * ptr){
 //   cout << "Entering function Sentence::setNext()" << endl;
    next = ptr;
  //  cout << "Leaving function Sentence::setNext()" << endl;
  }

Sentence * Sentence::getNext(){
 /*  cout << "Entering function Sentence::getNext()" << endl;
   cout << "Leaving function Sentence::getNext()" << endl; */
   return next;
}

char::Sentence::getPunct(){
   return punct;
}

void Sentence::setPunct(char c){
   punct = c;
}
  
   
