#ifndef _SEEKER_H_
#define _SEEKER_H_

#include <iostream>
using namespace std;

class Seeker
{
   long phno;
   string location;
   string blood_group;

   public:

   Seeker();
   void setPhno(long);
   void setLocation(string);
   void setBlood_group(string);
   long getPhno();
   string getLocation();
   string getBlood_group();
   ~Seeker();
};

#endif
