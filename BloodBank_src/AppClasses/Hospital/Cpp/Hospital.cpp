#include "../Include/Hospital.h"

Hospital :: Hospital () 
{
    this->name="";
    this->location="";
    this->id=0;
    this->sd="";
    this->ed="";
    this->ap=0;
    this->an=0;
    this->op=0;
    this->on=0;
    this->abp=0;
    this->abn=0;
    this->bp=0;
    this->bn=0;
    
}

void Hospital :: setName(string n)
{
    name=n;
}


void Hospital :: setId(int n)
{
    id=n;
}

void Hospital :: setSd(string name)
{
    sd=name;
}

void Hospital :: setEd(string name)
{
    ed=name;
}

void Hospital :: setLocation(string name)
{
    location=name;
}

void Hospital :: setAp(int l)
{
 ap=l;   
}


void Hospital :: setAn(int l)
{
 an=l;   
}


void Hospital :: setOp(int l)
{
 op=l;   
}

void Hospital :: setOn(int l)
{
 on=l;   
}

void Hospital :: setAbp(int l)
{
 abp=l;   
}

void Hospital :: setAbn(int l)
{
 abn=l;   
}

void Hospital :: setBp(int l)
{
 bp=l;   
}

void Hospital :: setBn(int l)
{
 bn=l;   
}


string Hospital :: getName()
{
    return name;
}

int Hospital :: getId()
{
    return id;
}

string Hospital :: getLocation()
{
    return location;
}

string Hospital :: getSd()
{
    return sd;
}

string Hospital :: getEd()
{
    return ed;
}

int Hospital :: getAp()
{
  return ap;
}

int Hospital :: getAn()
{
  return an;
}

int Hospital :: getOp()
{
  return op;
}

int Hospital :: getOn()
{
  return on;
}

int Hospital :: getAbp()
{
  return abp;
}

int Hospital :: getAbn()
{
  return abn;
}

int Hospital :: getBp()
{
  return bp;
}

int Hospital :: getBn()
{
  return bn;
}


Hospital :: ~Hospital()
{
}