#include <iostream>
#include "Lab2.h"
#include <boost/format.hpp>
using namespace std;

 

 void new_Voter(string &ln, string &fn, int &a, int &sNum, string &sName, string &t, int &zip,  float &amount){ 
    
       string a_Command;
       cout << "Last Name: ";
       cin >> ln;
       
       cout << "First Name: ";
       cin >> fn;
       cout << "Age: ";
       cin >> a;
       cout << "Street Name: ";
       cin >> sName;
       cout << "House Number: ";
       cin >> sNum;
       cout << "Town: ";
       cin >> t;
       cout << "Zip Code: ";
       cin >> zip;
       amount = 0;
     
     
  }

void update (string &ln, string &fn, int &a, int &sNum, string &sName, string &t, int &zip){
       string a_Command;
       cout << "Last Name: ";
       cin >> ln;
       cout << "First Name: ";
       cin >> fn;
       cout << "Age: ";
       cin >> a;
       cout << "Street Name: ";
       cin >> sName;
       cout << "House Number: ";
       cin >> sNum;
       cout << "Town: ";
       cin >> t;
       cout << "Zip Code: ";
       cin >> zip;
      
       

       
      
    
   
}

 void view(const string &last_Name, const string &first_Name, const int &Age, const int &street_Number, const string &street_Name, const string &town,  const int &zip_Code, const float &amount_Donated){
    string a_Command;
    cout << "Voter Info:" <<endl;
    cout << first_Name << " " << last_Name << ": " << "age " << Age << endl;
    cout << street_Number << " " << street_Name << endl;
    cout << town << ", " << "NY " << zip_Code << endl;
    cout << "Current Amount Donated: " << "$" << boost::format("%.2f") % amount_Donated << endl;
    cout << "\n";
    
}

   float donate( float &amount_Donated){
    
     cout << "Enter Amount to Donate: ";
     cin >> amount_Donated;
        
     cout << "$" << boost::format("%.2f") % amount_Donated << " donated." << endl;
     return amount_Donated;
    
   }
   
   
   void report(const float &amount_Donated){
	cout << "Current Amount Donated: $" << boost::format("%.2f") % amount_Donated << endl;
        
   }
          
     
     
   


    
     
     
 
 



        
      
       


