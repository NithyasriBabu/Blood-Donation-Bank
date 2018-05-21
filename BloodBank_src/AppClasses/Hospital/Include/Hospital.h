#ifndef _HOSPITAL_H_
#define _HOSPITAL_H_

#include <iostream>
using namespace std;

class Hospital
{
    string name;
    string location;
    string venue;
    string sd;
    string ed;
    int id,ap,an,bp,bn,op,on,abp,abn;
    
    public:
    Hospital();
    void setId(int);
    void setName(string);
    void setLocation(string);
    void setSd(string);
    void setEd(string);
    void setAp(int);
    void setAn(int);
    void setBp(int);
    void setBn(int);
    void setAbp(int); 
    void setAbn(int); 
    void setOp(int); 
    void setOn(int); 

    int getId();
    string getName();
    string getLocation();
    string getSd();
    string getEd();
    int getAp();
    int getAn();
    int getOp();
    int getOn();
    int getAbp();
    int getAbn();
    int getBp();
    int getBn();
   
    ~Hospital();
};

#endif
