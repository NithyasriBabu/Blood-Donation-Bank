#include "../Include/SeekerUI.h"
#include <sstream>
#include "../../../AppClasses/Seeker/Include/Seeker.h"
#include "../../../GlobalDefs/Include/GlobalDefs.h"
#include "../../../Model/Include/DB.h"
#include "../../../ExceptionClasses/SqlError/Include/SqlError.h"
#include<vector>

long SeekerUI :: getPhno()
{
   string s1="";
   int l=0;
   while(l!=10)
   {
     cout<<"\033[1;33m\n\t\tPhone Number: ";
     cin>>s1;
     if(s1.length()!=10)
     {
       cout<<"\033[1;31m\n\n\t\tEnter only correct 10 digit phone number\n\033[0m"<<endl;
       continue;
     }
     string s2="0123456789";
     if(strspn(s1.c_str(),s2.c_str())!=s1.length())
     {
       cout<<"\033[1;31m\n\n\t\tGiven Phone number contains Invalid Charecters\n\033[0m"<<endl;
       continue;
     }
     l=s1.length();
   }
   cout<<"\033[0m";
   long ph;
   ph=atol(s1.c_str());
   return ph;
}

string SeekerUI :: getLocation()
{
   string loc;
   static int f=0;
   do
   {
     cout<<"\033[1;33m\n\t\tSeeker Location : ";
     cin.ignore();
     getline(cin,loc);
     int asc;
     for(int i=0;i<loc.length();i++)
     {
      asc=int(loc[i]);
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
   return loc;
}

string SeekerUI :: getBloodGroup()
{

   string ubg;
   string type;
   string pon;
   do
   {
    cout<<"\033[1;33m\n\t\tEnter Blood Type Required (A,B,AB,O only) : ";
    cin>>type;
    if(!(type=="A" || type=="AB" || type=="B" || type=="O"))
    {
	cout<<"\033[1;31m\n\t\tPlease Enter Proper Blood Type\n\033[0m"; 
	continue;
    }

    do
    {
     cout<<"\033[1;33m\n\t\tEnter Rh Factor: Positve or Negative (+,- only): ";
     cin>>pon;
     if(!(pon=="+" || pon=="-"))
	cout<<"\033[1;31m\n\t\tPlease Enter only if +ve or Negative Using '+' or '-'\n\033[0m"; 
    }while(!(pon=="+" || pon=="-"));

   }while(!(type=="A" || type=="AB" || type=="B" || type=="O"));

   ubg=type+pon+"Ve";

   cout<<"\033[0m";
   return ubg;

}

void SeekerUI :: displayDonors(Seeker s,vector<Account> &l)
{
    
    cout<<"\033[1;36m\n\t\t**************************Seeker Information******************\033[0m";
    cout<<"\033[1;35m\n\t\t\tBlood Group : "<<s.getBlood_group()<<endl;
    cout<<"\n\t\t\tLocation : "<<s.getLocation()<<endl<<"\033[0m";
    cout<<"\033[1;36m\n\t\t**************************************************************\033[0m";

    if(l.size()!=0)
    {
     cout<<"\033[1;36m\n\t\t************************Donors Information*********************\n\n";
     cout<<"\033[1;32m\t\t"<<setw(15)<<setiosflags(ios::left)<<"Name"<<setw(11)<<setiosflags(ios::left)<<"Phone No."<<setw(15)<<setiosflags(ios::left)<<"Blood Group"<<setw(20)<<setiosflags(ios::left)<<"Location\n";
     for(int i=0;i<l.size();i++)
	cout<<"\n\t\t"<<setw(15)<<setiosflags(ios::left)<<l[i].getUname()<<setw(11)<<setiosflags(ios::left)<<l[i].getUphno()<<setw(15)<<setiosflags(ios::left)<<l[i].getUblood_group()<<setw(20)<<setiosflags(ios::left)<<l[i].getUlocation()<<endl;
    }
    else
	cout<<"\033[1;31m\n\t\tSorry.. There are no donors for "<<s.getBlood_group()<<" in "<<s.getLocation()<<"\n\033[0m";
    cout<<"\033[0m";

}

void SeekerUI:: generateDonorsReport(Seeker s, vector<Account> &l)
{
     fstream wf;
     string fn=s.getBlood_group()+"_"+DB::dbNow();

     char g[30];
     strcpy(g,fn.c_str());
     wf.open(g,ios::out|ios::trunc);
     if(wf.is_open() && l.size()>0)
     {
        wf<<"\n**************************Seeker Information******************\n";
        wf<<"\n\tBlood Group : "+s.getBlood_group()+"\n";
        wf<<"\n\tLocation : "+s.getLocation()+"\n";
        wf<<"\n**************************************************************\n";
        wf<<"\n******************Donors Information*********************\n";
        wf<<"\033[1;32m\t\t"<<setw(15)<<setiosflags(ios::left)<<"Name"<<setw(11)<<setiosflags(ios::left)<<"Phone No."<<setw(15)<<setiosflags(ios::left)<<"Blood Group"<<setw(20)<<setiosflags(ios::left)<<"Location\n";
        for(int i=0;i<l.size();i++)
           wf<<"\n\t\t"<<setw(15)<<setiosflags(ios::left)<<l[i].getUname()<<setw(11)<<setiosflags(ios::left)<<l[i].getUphno()<<setw(15)<<setiosflags(ios::left)<<l[i].getUblood_group()<<setw(20)<<setiosflags(ios::left)<<l[i].getUlocation()<<endl;
    wf.close();
    }
    else
        cout<<"\033[1;31m\n\t\tDonors List Not generated.\n\n\033[0m";

}


void SeekerUI :: displayTags(Seeker s,vector<Account> &tgl)
{
    cout<<"\033[1;36m\n\t\t**************************Seeker Information******************\n\033[0m";
    cout<<"\033[1;35m\n\t\t\tPhone Number : "<<s.getPhno()<<endl;
    cout<<"\n\t\t\tLocation : "<<s.getLocation()<<endl<<"\033[0m\n";
    cout<<"\033[1;36m\n\t\t**************************************************************\n\033[0m";
    
    if(tgl.size()>0)
    {
      cout<<"\033[1;36m\n\t\t******************Tagged Donor Information*********************\n\n\033[0m";
      cout<<"\033[1;32m\t\t"<<setw(19)<<setiosflags(ios::left)<<"Name"<<setw(11)<<setiosflags(ios::left)<<"Phone No."<<setw(15)<<setiosflags(ios::left)<<"Blood Group"<<setw(20)<<setiosflags(ios::left)<<"Location\n";
      for(int i=0;i<tgl.size();i++)
      {
       
        {
	 cout<<"\n\t\t"<<setw(15)<<setiosflags(ios::left)<<tgl[i].getUname()<<setw(11)<<setiosflags(ios::left)<<tgl[i].getUphno()<<setw(15)<<setiosflags(ios::left)<<tgl[i].getUblood_group();
	 cout<<setw(20)<<setiosflags(ios::left)<<tgl[i].getUlocation()<<endl;
	}
      }
    }
    else
      cout<<"\033[1;31m\t\tSorry ."<<s.getPhno()<<" dosen't have preffered donors in  "<<s.getLocation()<<"\n\033[0m";
    cout<<"\033[0m";
}

void SeekerUI:: generateTagsReport(Seeker s, vector<Account> &tgl)
{
     fstream wf;
     string fn=Utility::toString(s.getPhno())+"_"+DB::dbNow();
     
     char g[30];
     strcpy(g,fn.c_str());
     wf.open(g,ios::out|ios::trunc);
     if(wf.is_open() && tgl.size()>0)
     {
	wf<<"\n**************************Seeker Information******************\n";
	wf<<"\n\tPhone Number : "+Utility::toString(s.getPhno())+"\n";
	wf<<"\n\tLocation : "+s.getLocation()+"\n";
	wf<<"\n**************************************************************\n";
	wf<<"\n******************Tagged Donor Information*********************\n";
	wf<<"\n\tName\t\tPhone No.\t\tBlood Group\t\tLocation\n\n";
	for(int i=0;i<tgl.size();i++)
	{
		string s="\n\t"+tgl[i].getUname()+"\t\t"+Utility::toString(tgl[i].getUphno())+"\t\t"+tgl[i].getUblood_group()+"\t\t"+tgl[i].getUlocation()+"\n\n";
		wf<<s;
	}
	wf.close();
     }
     else
	cout<<"\033[1;31m\n\t\tReport for Tags Not generated.\n\n\033[0m";
}

void SeekerUI::displayNoTags(long s)
{
    cout<<"\033[1;31m\n\t\t"<<s<<" does not have any preferred Donors.Please use Search By BloodGroup and Location Option...!\033[0m";
}

void SeekerUI::displayTagReportSuccess(long p,string s)
{
    cout<<"\033[1;32m\n\t\tThe Search Result for "<<p<<" with file name "<<s<<"has been generated!!! \033[0m";
}

void SeekerUI::displayDonorReportSuccess(string b,string s)
{
    cout<<"\033[1;32m\n\t\tThe Search Result for "<<b<<" with file name "<<s<<"has been generated!!! \033[0m";
}
 
