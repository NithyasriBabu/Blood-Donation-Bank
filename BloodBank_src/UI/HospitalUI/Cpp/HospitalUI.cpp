#include "../Include/HospitalUI.h"
#include "../../../Model/Include/DB.h"
#include "../../../GlobalDefs/Include/GlobalDefs.h"
#include<string.h>
#include<vector>

string HospitalUI :: getName()
{
   string un;
   static int f=0;
   int ch;
   do
   {
     cout<<"\033[1;33m\n\t\tHospital Name : ";
     cin.ignore();
     getline(cin,un);
     int asc;
     for(int i=0;i<un.length();i++)
     {
      asc=int(un[i]);
      if(asc>=33 && asc<=64||asc>=91 && asc<=96||asc<=123 && asc >=126)
       f=1;
     }
     if(f==1)
     {
       cout<<"\033[1;31m\n\n\t\tPlease enter only characters for Name\033[0m";
       f=0;
     }
     else
      f=2;
    
   }while(f==0);
   cout<<"\033[0m";
  return un;
}

string HospitalUI :: getLocation()
{
   string ul;
   static int f=0;
   do
   {
     cout<<"\033[1;33m\n\t\tUser Location : ";
     getline(cin,ul);
     int asc;
     for(int i=0;i<ul.length();i++)
     {
      asc=int(ul[i]);
      if(asc>=33 && asc<=64||asc>=91 && asc<=96||asc<=123 && asc >=126)
       f=1;
     }
     if(f==1)
     {
       cout<<"\033[1;31m\n\n\t\tPlease enter only characters for location\033[0m";
       f=0;
     }
     else
      f=2;
    
   }while(f==0);
   cout<<"\033[0m";
   return ul;
}

void HospitalUI :: getDates(Hospital &h)
{
   string sd;
   cout<<"\033[1;33m\n\t\tStart Date Of Blood Camp (Format: DD-MMM-YYYY Eg. 07-JUL-2014) : ";
   cin>>sd;
   cout<<"\033[0m";
   h.setSd(sd);

   string ed;
   cout<<"\033[1;33m\n\t\tEnd Date Of Blood Camp (Format: DD-MMM-YYYY Eg. 07-JUL-2014) : ";
   cin>>ed;
   int check = DB::dbDateCon(ed);
   cout<<"\033[0m";
   h.setEd(ed);

}

int HospitalUI :: getId()
{
   int i;
   cout<<"\033[1;33m\n\t\tHospital ID: ";
   cin>>i;
   cout<<"\033[0m";
   return i;
}

void HospitalUI :: getStock(Hospital &h)
{
   int ap,an,bp,bn,op,on,abp,abn;
   cout<<"\033[1;33m\n\t\tA+ve Stock: ";
   cin>>ap;
   h.setAp(ap);

   cout<<"\033[1;33m\n\t\tA-ve Stock: ";
   cin>>an;
   h.setAn(an);

   cout<<"\033[1;33m\n\t\tB+ve Stock: ";
   cin>>bp;
   h.setBp(bp);

   cout<<"\033[1;33m\n\t\tB-ve Stock: ";
   cin>>bn;
   h.setBn(bn);

   cout<<"\033[1;33m\n\t\tAB+ve Stock: ";
   cin>>abp;
   h.setAbp(abp); 

   cout<<"\033[1;33m\n\t\tAB-ve Stock: ";
   cin>>abn;
   h.setAbn(abn); 

   cout<<"\033[1;33m\n\t\tO+ve Stock: ";
   cin>>op;
   h.setOp(op); 

   cout<<"\033[1;33m\n\t\tO-ve Stock: ";
   cin>>on;
   h.setOn(on);    
   cout<<"\033[0m";
}

void HospitalUI::displayHospitals(vector<Hospital> hs)
{
    cout<<"\033[1;32m\n\n\t\tList of Hospitals\n\n\033[0m";
    for(int i=0;i<hs.size();i++)
          cout<<"\033[1;32m\n\t\t"<<hs[i].getId()<<"\t\t"<<hs[i].getName()<<"\t\t"<<hs[i].getLocation()<<"\n\033[0m";
}