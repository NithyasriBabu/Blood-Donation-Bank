#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
using namespace std;

class Account
{
    string uname;
    long uphno;
    string ulocation;
    string ublood_group;
    string ldod;
    long tag_phno;
    char status;
    string upass;
    string last_login;

    public:
    Account();
    void setUname(string);
    void setUphno(long);
    void setUlocation(string);
    void setUblood_group(string);
    void setUldod(string);
    void setTag_phno(long);
    void setStatus(char);
    void setUpass(string);
    void setLastLogin(string);

    string getUname();
    long getUphno();
    string getUlocation();
    string getUblood_group();
    string getUldod();
    long getTag_phno();
    char getStatus();
    string getUpass();
    string getLastLogin();

    ~Account();
};

#endif
