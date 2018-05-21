#include "../Include/Seeker.h"

Seeker :: Seeker()
{
  this->phno=0;
  this->blood_group="";
  this->location="";
}

void Seeker:: setPhno(long number)
{
    phno=number;
}

void Seeker :: setLocation(string loc)
{
    location=loc;
}

void Seeker :: setBlood_group(string bl_gr)
{
    blood_group=bl_gr;
}

long Seeker :: getPhno()
{
    return phno;
}

string Seeker :: getLocation()
{
    return location;
}

string Seeker :: getBlood_group()
{
    return blood_group;
}

Seeker :: ~Seeker()
{
}