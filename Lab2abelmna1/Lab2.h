#include <iostream>
using namespace std;

/*void new_Voter(string *ln, string *fn, int *a, int *sNum, string *sName, string *t, int *zip, float *amount);
void update(string *ln, string *fn, int *a, int *sNum, string *sName, string *t, int *zip);
void view(string *last_Name, string *first_Name, int *Age, int *street_Number, string *street_Name, string *town,  int *zip_Code, float *amount_Donated);
float donate(float *amount_Donated);
void report(float *amount_Donated); */



void new_Voter(string &ln, string &fn, int &a, int &sNum, string &sName, string &t, int &zip,  float &amount);
void update (string &ln, string &fn, int &a, int &sNum, string &sName, string &t, int &zip);
void view(const string &last_Name, const string &first_Name, const int &Age, const int &street_Number, const string &street_Name, const string &town,  const int &zip_Code, const float &amount_Donated);
float donate(float &amount_Donated);
void report(const float &amount_Donated);
