#include "Story.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <string>
using namespace std;


Story::Story(){
//cout << "Entering function Story::Story()" << endl;
head = NULL; is_piggy = false;

//cout << "Leaving function Story::Story()" << endl;
}


bool Story::fileExists(string file_name){
   const char * a_file = file_name.c_str();
   ifstream infile(a_file);
   return infile.good();
}

   

Story::Story(string file_name){
  // cout << "Entering Story(file_name)" << endl;
 //bool headSet = false; Paragraph * newHead;
 if(!fileExists(file_name)){
    cout << "This file doesn't exist." << endl;
    head = NULL; is_piggy = false;
 }
 else{
   
   const char * fileString = file_name.c_str();
   ifstream myFile(fileString);
   string line;
  
   
   Paragraph * temp;
   if(myFile.is_open()){   //file is still open
        getline(myFile, line);
      head = new Paragraph(line);
      
      temp = head;
      while(getline(myFile,line)){
         temp->setNext(new Paragraph(line));
         temp = temp->getNext();
      }
      myFile.close();
      temp->setNext(NULL);
    }
    is_piggy = false;
 }

// cout << "Leaving Story(file_name)" << endl; 
}
   
   
   
   
   
 
   


Story::Story(const Story &s1){
 // cout << "Entering function Story::copyConstructor" << endl;
  if(s1.head == NULL) return;
  else{
    head = new Paragraph(*s1.head);
    Paragraph * temp = s1.head->getNext();
    Paragraph * ntemp = head;
    while(temp != NULL){
       ntemp->setNext(new Paragraph(*temp));
       temp = temp->getNext();
       ntemp = ntemp->getNext();
    }
    ntemp->setNext(NULL);
  }
  is_piggy = s1.is_piggy;
    
  
 // cout << "Leaving function Story::copyConstructor" << endl;
} 

void Story::show(){
 /* cout << "Entering function Story::show()" << endl;
  cout << "Story.is_piggy = " << is_piggy << endl;
  cout << "Leaving function Story::show()" << endl; */
}

Story::~Story(){
 //cout << "Entering function Story::~Story()" << endl;
  Paragraph * temp2 = head;
  Paragraph * temp3 = head;
  while(temp2 != NULL){
    temp3 = temp3->getNext();
    delete (temp2);
    temp2 = temp3;
  }


 //cout << "Leaving function Story::~Story()" << endl;
}

Story Story::operator+(const Story& story2) const{
 //  cout << "Entering function Story::operator+Story()" << endl;
   Story story1(*this); 
   Paragraph * story2_temp = story2.head; 
   
   if(story2_temp == NULL) return story1; 
   
   Paragraph * temp = story1.head;
   while(temp->getNext() != NULL){
     temp = temp->getNext();
   }
   
  
   while(story2_temp != NULL){
     temp->setNext(new Paragraph(*story2_temp));
     temp = temp->getNext();
     story2_temp = story2_temp->getNext();
   } 

   

 //  cout << "Leaving function Story::operator+Story()" << endl;
   return story1;
}

Story Story::operator+(const Paragraph& a_paragraph) const{
  // cout << "Entering function Story::Operator+Paragraph()" << endl;
   Story new_story(*this);
   if(new_story.head == NULL){
     new_story.setHead(new Paragraph(a_paragraph));
    //  (new_story.head)->setNext(NULL);   ===> MIGHT BE NECESSARY
     return new_story;
   }
   
   Paragraph * temp = new_story.head;

   while(temp->getNext() != NULL){
     temp = temp->getNext();
   }
   temp->setNext(new Paragraph(a_paragraph));
   temp = temp->getNext();
   temp->setNext(NULL);

   


  //   cout << "Leaving function Story::Operator+Paragraph()" << endl;
   return new_story;
}

Story Story::operator++(int i){
 //  cout << "Entering function Story::Operator++&Story()" << endl;
   Story s(*this);
 //  if(s.head == NULL) return; 
   Paragraph * temp = head;
   while(temp != NULL){
      (*temp)++;
      temp = temp->getNext();
   }   


  // cout << "Leaving function Story::Operator++&Story()" << endl;
   return s;
}

Story Story::operator--(int i){
  // cout << "Entering function Story::Operator--&Story()" << endl;
   Story s(*this);
   //               if(s.head == NULL) return;
   Paragraph * temp = head;
   while(temp != NULL){
      (*temp)--;
      temp = temp->getNext();
   }  

 //cout << "Leaving function Story::Operator--&Story()" << endl;
   return s;
}

Story &Story::operator+(int i){
  // cout << "Entering function Story::Operator+(int i)" << endl;
   if(i == 1){
     Paragraph * temp = head;
    // if(temp == NULL) return (*this);
       while(temp != NULL){
          (*temp) + 1;
          temp = temp->getNext();
       }
   }
 //  cout << "Leaving function Story::Operator+(int i)" << endl;
   return (*this);
}

Story &Story::operator++(){
 // cout << "Entering function Story::operator++()" << endl;
  if(head == NULL) return (*this);
  if(!is_piggy){
    Paragraph * temp = head;
    while(temp != NULL){
      ++(*temp);
      temp = temp->getNext();
    }
    is_piggy = true;
  }
 // cout << "Leaving function Story::operator++()" << endl;
  return (*this);
}

Story &Story::operator--(){
  // cout << "Entering function Story::operator--()" << endl;
  if(head == NULL) return (*this);
  if(is_piggy){
     Paragraph * temp = head;
     while(temp != NULL){
       --(*temp);
       temp = temp->getNext();
     }
     is_piggy = false;
   }
  // cout << "Leaving function Story::operator--()" << endl; 
   return (*this);
}

ostream& operator<<(ostream& out, const Story& story){
 // cout << "Entering function Story::operator<<" << endl;
  if(story.head == NULL){
     out << "Story is empty" << endl;
     return out;
  }
  Paragraph * temp = story.head;
  while(temp != NULL){
   out << (*temp) << '\n' ;
   temp = temp->getNext();
  }    
    
 // cout << "Leaving function Story::operator<<" << endl;
  return out;
}

Story &Story::operator=(const Story& a_story){
 // cout << "Entering function Story::operator=()" << endl;
 Paragraph * temp = head;

  if(a_story.head == NULL) return (*this);
 
 Story * story = new Story(a_story);  //MIGHT BE WRONG **************
 Paragraph * temp2 = head;
 Paragraph * temp3 = head;
 while(temp2 != NULL){
   temp3 = temp3->getNext();
   delete (temp2);
   temp2 = temp3;
 }
 (*this).setHead(story->getHead());
 is_piggy = a_story.is_piggy;


//cout << "Leaving function Story::operator=()" << endl; 
  return (*this);
}

Story Story::rest(){
   cout << "Entering function Story::rest()" << endl;
    
   Paragraph * temp = head;
   Story null_story;
   if(temp == NULL || temp->getNext() == NULL) return null_story;
  
   temp = temp->getNext();
   Story s;
   Paragraph * pnode = new Paragraph(*temp);
   s.setHead(pnode);
   temp = temp->getNext();
   while(temp != NULL){
     pnode->setNext(new Paragraph(*temp));
     temp = temp->getNext();
     pnode = pnode->getNext();
   }
   








   /* Word * temp = head;
  Sentence null_sent;
  if(temp == NULL || temp->getNext() == NULL) return null_sent;

  temp = temp->getNext();  //NEW HEAD THAT WE WANT
  Sentence s;
  Word * snode = new Word(*temp);
  s.setHead(snode);
  temp = temp->getNext();
  while(temp != NULL){
    snode->setNext(new Word(*temp));
    temp = temp->getNext();
    snode = snode->getNext();
  } */









  // cout << "Leaving function Story::rest()" << endl;
   return s;
}

Paragraph Story::first(){
  // cout << "Entering function Story::first()" << endl;
  
   Paragraph * temp = head;
   Paragraph p(*head);
   if(temp == NULL) return (*head);   

 //  cout << "Leaving function Story::first()" << endl;
   return p;
}

void Story::save(string f){
  // cout << "Entering function Story::save()" << endl;
  string new_file; ofstream myFile;
  
  const char * a_file = f.c_str();  
  Paragraph * temp = head;

   myFile.open(a_file);
  while(temp != NULL){
    myFile << (*temp);
    temp = temp->getNext();
  } 
     
      
     




  //cout << "Leaving function Story::save()" << endl; 
}

void Story::setHead(Paragraph * ptr){
   // cout << "Entering function Story::setHead()" << endl;
     head = ptr;
   // cout << "Leaving function Story::setHead()" << endl;
}

Paragraph * Story::getHead(){
 //   cout << "Entering function Story::getHead()" << endl;
    return head;
   // cout << "Leaving function Story::getHead()" << endl;
}
      
