#include "Paragraph.h"
#include <iostream>
using namespace std;


Paragraph::Paragraph(){
/*cout << "Entering function Paragraph::Paragraph()" << endl;
 cout << "Leaving function Paragraph::Paragraph()" << endl; */
 head = NULL;
 next = NULL;
 is_piggy = false;
}

void Paragraph::show(){
   /*cout << "Entering function Paragraph::show()" << endl;
   cout << "Show() will print out PARAGRAPH'S data members in a neat format." << endl;
   cout << "Leaving function Paragraph::show()" << endl; */
}

Paragraph::~Paragraph(){
 // cout << "Entering function Paragraph::~Paragraph()"<< endl;
  Sentence * temp2 = head;
  Sentence * temp3 = head;
  while(temp2 != NULL){
    temp3 = temp3->getNext();
    delete (temp2);
    temp2 = temp3;
  }
 // cout << "Leaving function Paragraph::~Paragraph()" << endl;
}

Paragraph::Paragraph(const Paragraph &p1){
 // cout << "Entering function Paragraph::copyConstructor" << endl;
  
  if(p1.head == NULL) return;
  else{
    head = new Sentence(*p1.head);
    Sentence * temp = p1.head->getNext();
    Sentence * ntemp = head;
    while(temp != NULL){
      ntemp->setNext(new Sentence(*temp)); 
      temp = temp->getNext();
      ntemp = ntemp->getNext();
    }
    ntemp->setNext(NULL);
    next = NULL;
   }
  is_piggy = p1.is_piggy;
 // cout << "Leaving function Paragraph::copyConstructor" << endl;
} 

Paragraph::Paragraph(string s){
 //cout << "Entering function Paragraph::Paragraph(value)" << endl;
  //bool headSet = false;
  if(s.length() == 0){
    head = NULL; next = NULL; is_piggy = false;
  }
  else{
    //string streamAgain = s;
    string word;
    string sentence;
    //Sentence * newHead;
    Sentence * temp;
    string sappend = "";
    istringstream stream(s);
    int i;
    while(stream >> word){
       
       if(word.at(word.length()-1) == '.' || word.at(word.length()-1) == '!' ||
         word.at(word.length()-1) == '?'){
         sappend = sappend + " " + word;
         sentence = sappend;
         head = new Sentence(sentence);
         break;
         //(*newHead).setPunct(word.at(word.length() - 1));
       }
       else{
         sappend = sappend + " " + word;
       }
     }
    temp = head;
    sappend = "";
    
    while(stream >> word){
       sappend = sappend + " " + word;
       if(word.at(word.length()-1) == '.' || word.at(word.length()-1) == '!' ||
         word.at(word.length()-1) == '?'){
         temp->setNext(new Sentence(sappend));
         temp = temp->getNext();
       }
    }
    temp->setNext(NULL);
    next = NULL;
    is_piggy = false;
  }
         
  //cout << "Leaving function Paragraph::Paragraph(value)" << endl;   
}
 

  
         
      
    





  


Story Paragraph::operator+(const Story& a_story) const{
 //  cout << "Entering function Paragraph::Operator+Story()" << endl;
  
    
   Story new_story(a_story);
   if(new_story.getHead() == NULL) return new_story;
   Story * story_node = &new_story;
   Paragraph * p = new Paragraph(*this);
   Paragraph * s_head = new_story.getHead();
  // Paragraph * pnode = p;
   p->setNext(new_story.getHead());
   story_node->setHead(p);
   
  // cout << "Leaving function Paragraph::Operator+Story()" << endl;
   return new_story;
}

Paragraph Paragraph::operator+(const Paragraph& a_paragraph) const{
  // cout << "Entering function Paragraph::Operator+Paragraph()" << endl;
   Paragraph p1(*this); Sentence * p2_head = a_paragraph.head; 
   if(p2_head == NULL) return p1; 
   
   //Paragraph * p2 = new Paragraph(a_paragraph);
   Sentence * temp = p1.head;
   while(temp->getNext() != NULL){
     temp = temp->getNext();
   }
   
  
  Sentence * p2_temp = a_paragraph.head;
   while(p2_temp != NULL){
     temp->setNext(new Sentence(*p2_temp));
     temp = temp->getNext();
     p2_temp = p2_temp->getNext();
   }
   
  


 

//  p1.setNext(NULL);    =====> CONSTRUCTOR MIGHT TAKE CARE OF THIS   




 //  cout << "Leaving function Paragraph::Operator+Paragraph()" << endl;     
   return p1;
}

Paragraph Paragraph::operator+(const Sentence& a_sentence) const{
 //   cout << "Entering function Paragraph::Operator+Sentence()" << endl;
     Paragraph new_paragraph(*this);
   // Sentence * temp = new_paragraph.head;
    if(new_paragraph.head == NULL){
      Sentence s(a_sentence); //check to see if sentence is empty
      if(s.getHead() != NULL){
      new_paragraph.head = new Sentence(a_sentence);
      (new_paragraph.head)->setNext(NULL);
      }
      //new_paragraph.setNext(NULL) =====> MIGHT BE NECESSARY
      return new_paragraph;
    }
    
    Sentence * temp = new_paragraph.head;
    
    while(temp->getNext() != NULL){
       temp = temp->getNext();
    }
    temp->setNext(new Sentence(a_sentence));
    temp = temp->getNext();
    temp->setNext(NULL);
    
   //new_paragraph.setNext(NULL);   =====> MIGHT BE NECESSARY
      
    
  //  cout << "Leaving function Paragraph::Operator+Sentence()" << endl;
    return new_paragraph;
}

Paragraph Paragraph::operator++(int i){
 // cout << "Entering function Paragraph::operator++&Paragraph()" << endl;

  Paragraph p(*this);
  Sentence * temp = head;
  if(temp == NULL) return p;
  while(temp != NULL){
     (*temp)++;
     temp = temp->getNext();
  }
   
   

 // cout << "Entering function Paragraph::operator++&Paragraph()" << endl;
  return p;
}

Paragraph Paragraph::operator--(int i){
 // cout << "Entering function Paragraph::operator--&Paragraph()" << endl;
  Paragraph p(*this);
  Sentence * temp = head;
  if(temp == NULL) return p;
  while(temp != NULL){
    (*temp)--;
    temp = temp->getNext();
  }

   

 //  cout << "Entering function Paragraph::operator--&Paragraph()" << endl;
  return p;
}

Paragraph &Paragraph::operator+(int i){
 // cout << "Entering function Paragraph::operator+(int i)" << endl;
  if(head == NULL) return (*this);
  if(i == 1){
      Sentence * temp = head;
     
    
     while(temp != NULL){
       (*temp)+1;
       temp = temp->getNext();
     }
   }
 // cout << "Leaving function Paragraph::operator+(int i)" << endl;
  return (*this);
}

Paragraph &Paragraph::operator++(){
 // cout << "Entering function Paragraph::operator++()" << endl;
  if(head == NULL) return (*this);
  if(!is_piggy){
    Sentence * temp = head;
    while(temp != NULL){
      ++(*temp);
      temp = temp->getNext();
    }
    is_piggy = true;
  }
 // cout << "Leaving function Paragraph::operator++()" << endl;
  return (*this);
}

Paragraph &Paragraph::operator--(){
 // cout << "Entering function Paragraph::operator--()" << endl;
  if(head == NULL) return (*this);
  if(is_piggy){
    Sentence * temp = head;
    while(temp != NULL){
      --(*temp);
      temp = temp->getNext();
    }
   is_piggy = false;
  }
    


//cout << "Leaving function Paragraph::operator--()" << endl; 
  return (*this);
}

ostream& operator<<(ostream& out, const Paragraph& p){
 //  cout << "Entering function Paragraph::operator<<()" << endl;
   out << '\t';
   Sentence * temp = p.head;
   while(temp != NULL){
       out << (*temp);
       temp = temp->getNext();
     
   // temp = temp->getNext();
  }
  out << '\n';

  // cout << "Leaving function Paragraph::operator<<()" << endl;
  return out;
}

Paragraph &Paragraph::operator=(const Paragraph& a_paragraph){
 // cout << "Entering function Paragraph::operator=()" << endl;
  /*Assign data members here */
 // cout << "Leaving function Paragraph::operator=()" << endl;
  Sentence * temp = head;
  
  Paragraph * p = new Paragraph(a_paragraph);
  Sentence * temp2 = head;
  Sentence * temp3 = head;
  while(temp2 != NULL){
    temp3 = temp3->getNext();
    delete temp2;
    temp2 = temp3;
  }
  (*this).setHead(p->getHead());
  is_piggy = a_paragraph.is_piggy;


  return (*this);
}

Sentence Paragraph::first(){
  // cout << "Entering function Paragraph::first()" << endl;
  
   Sentence null_s;
   Sentence * temp = head;
   if(temp == NULL) return null_s;
   Sentence s(*temp);

   
 //  cout << "Entering function Paragraph::first()" << endl;
   return s;
}

Paragraph Paragraph::rest(){
  // cout << "Entering function Paragraph::rest()" << endl;
  
   Sentence * temp = head;
   Paragraph null_paragraph;
   if(temp == NULL || temp->getNext() == NULL) return null_paragraph;

   temp = temp->getNext();
   Paragraph p;
   Sentence * pnode = new Sentence(*temp);
   p.setHead(pnode);
   temp = temp->getNext();
   while(temp != NULL){
      pnode->setNext(new Sentence(*temp));
      temp = temp->getNext();
      pnode = pnode->getNext();
   }



 // cout << "Entering function Paragraph::rest()" << endl;
   return p;
}

void Paragraph::setHead(Sentence * ptr){
  //cout << "Entering function Paragraph::setHead()" << endl;
  head = ptr;
  //cout << "Leaving function Paragraph::setHead()" << endl;
}

void Paragraph::setNext(Paragraph * ptr){
  //cout << "Entering function Paragraph::setNext()" << endl;
  next = ptr;
  //cout << "Leaving function Paragraph::setNext()" << endl;
}

Sentence * Paragraph::getHead(){
   /*cout << "Entering function Paragraph::getNext()" << endl;
   cout << "Leaving function Paragraph::getNext()" << endl; */
   return head;
}

Paragraph * Paragraph::getNext(){
  /* cout << "Entering function Paragraph::getNext()" << endl;
   cout << "Leaving function Paragraph::getNext()" << endl; */
   return next;
}
   
