#include <iostream>
#include "Lab2.h"
#include <boost/format.hpp>
using namespace std;

int main(int argc, char *argv[]){
   string a_Command; string last_Name; string first_Name; int Age; int street_Number; 
   string street_Name; string town; int zip_Code; float amount_Donated; float sum = 0;
     cout << "Enter a command.\n";
     cout << "Choose from ['New', 'View', 'Update', 'Donate', 'Report', 'Quit'].\n: ";
     cin >> a_Command;
       while(a_Command != "Quit"){
          if(a_Command != "New" && a_Command != "View" && a_Command != "Update" && a_Command != "Donate" && a_Command != "Report" && a_Command != "Quit"){ 
            cout << "Command not recognized. Please try again.\n" << endl;
            cout << "Enter a command.\n";
            cout << "Choose from ['New', 'View', 'Update', 'Donate', 'Report', 'Quit'].\n: ";
            cin >> a_Command;
          }else{
            if(a_Command == "New"){
              new_Voter(last_Name, first_Name, Age, street_Number, street_Name, town, zip_Code, amount_Donated);
              cout << "Enter a command.\n";
              cout << "Choose from ['New', 'View', 'Update', 'Donate', 'Report', 'Quit'].\n: ";
              cin >> a_Command;
             }
             if(a_Command == "Update"){
              update(last_Name, first_Name, Age, street_Number, street_Name, town, zip_Code);
              cout << "Enter a command.\n";
              cout << "Choose from ['New', 'View', 'Update', 'Donate', 'Report', 'Quit'].\n: ";
              cin >> a_Command;
             }
             if(a_Command == "View"){
              view(last_Name, first_Name, Age, street_Number, street_Name, town, zip_Code, sum);
              cout << "Enter a command.\n";
              cout << "Choose from ['New', 'View', 'Update', 'Donate', 'Report', 'Quit'].\n: ";
              cin >> a_Command;
             }
             if(a_Command == "Donate"){
              float value = donate(amount_Donated); 
              sum += value;
              cout << "Enter a command.\n";
              cout << "Choose from ['New', 'View', 'Update', 'Donate', 'Report', 'Quit'].\n: ";
              cin >> a_Command;
             }
             if(a_Command == "Report"){
               report(sum);
               cout << "Enter a command.\n";
               cout << "Choose from ['New', 'View', 'Update', 'Donate', 'Report', 'Quit'].\n: ";
               cin >> a_Command;
             }
               
              if(a_Command == "Quit"){
              return 0;
             }
          }
          
     }
     
}
