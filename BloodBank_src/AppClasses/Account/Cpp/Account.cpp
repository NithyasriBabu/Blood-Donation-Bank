#include "../Include/Account.h"

Account :: Account () 
{
    this->uname="";
    this->uphno=0;
    this->ulocation="";
    this->ublood_group="";
    this->ldod="";
    this->tag_phno=0;
    this->status='y';
    this->upass="";
    this->last_login="";
}

void Account :: setUname(string name)
{
    uname=name;
}

void Account :: setUphno(long number)
{
    uphno=number;
}

void Account :: setUlocation(string location)
{
    ulocation=location;
}

void Account :: setUblood_group(string bl_gr)
{
    ublood_group=bl_gr;
}

void Account :: setUldod(string ld)
{
    ldod=ld;
}

void Account :: setTag_phno(long tphno)
{
    tag_phno=tphno;
}

void Account :: setStatus(char st)
{
    status=st;
}

void Account :: setUpass(string pass)
{
   upass=pass;
}

void Account :: setLastLogin(string ll)
{
    last_login=ll;
}

string Account :: getUname()
{
    return uname;
}

long Account :: getUphno()
{
    return uphno;
}

string Account :: getUlocation()
{
    return ulocation;
}

string Account :: getUblood_group()
{
    return ublood_group;
}

string Account :: getUldod()
{
    return ldod;
}

long Account :: getTag_phno()
{
    return tag_phno;
}

char Account :: getStatus()
{
    return status;
}

string Account :: getUpass()
{
    return upass;
}

string Account :: getLastLogin()
{
    return last_login;
}

Account :: ~Account()
{
}