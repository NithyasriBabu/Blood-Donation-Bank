#include "../Include/AccountUI.h"
#include "../../../Model/Include/DB.h"
#include "../../../GlobalDefs/Include/GlobalDefs.h"
#include<string.h>

string AccountUI :: getUname()
{
   string un;
   static int f=0;
   int ch;
   do
   {
     cout<<"\033[1;33m\n\t\tUser Name : ";
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

string AccountUI :: getUpass()
{
   string ups;
   cout<<"\033[1;33m";
   char *up=getpass("\n\t\tPassword  :");
   ups=string(up);
   cout<<"\033[0m";
   return ups;
}

string AccountUI :: getDetails()
{
  string fn;
  cout<<"\033[1;33m";
  cout<<"\n\t\tFile Name: ";
  cin>>fn;
  cout<<"\033[0m";
  return fn;
} 

long AccountUI :: getUphno()
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
   long uph;
   uph=atol(s1.c_str());
   return uph;
}
string AccountUI :: getUlocation()
{
   string ul;
   static int f=0;
   do
   {
     cout<<"\033[1;33m\n\t\tUser Location : ";
     cin.ignore();
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

string AccountUI :: getUblood_group()
{
   string ubg;
   string type;
   string pon;
   do
   {
    cout<<"\033[1;33m\n\t\tBlood Type (A,B,AB,O only) : ";
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

string AccountUI :: getUldod()
{
   string uld;
   er:
   cout<<"\033[1;33m\n\t\tLast Blood Donated Date (Format: DD-MMM-YYYY Eg. 07-JUL-2014) : ";
   cin>>uld;
   int check = DB::dbDateCon(uld);
   if(check==0)
   {
     cout<<"\033[1;31m\n\t\tPlease Enter Date Before Current Date.\n\033[0m";
     goto er;
   }
   cout<<"\033[0m";
   return uld;
}

char AccountUI :: getStatus()
{
   char us;  
   while(true)
   {
    cout<<"\033[1;33m\n\t\tWant to become Donor (Y/N) : ";
    cin>>us;
    if ((us=='Y')||(us=='y'))
       return us;
    else if((us=='N')||(us=='n'))
       return us;
    else
    {
       cin.clear();
       cin.ignore();
       cout<<"\033[1;31m\n\n\t\tEnter only (Y/N)\033[0m";
       continue;
    }
   }
   cout<<"\033[0m";
   return us;
}

int AccountUI :: LoginOption()
{
   cout<<"\033[1;33m\n\t\tLogin Types\n\t\t\t1.Direct Login\n\t\t\t2.Login from File\n";

   int l_UserInput;
   cout<<"\033[1;33m\n\t\tEnter Choice (E.g. 1) : ";
    
   while(!(cin>>l_UserInput))
   {  
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[1;31m\n\t\tEnter correct choice 1 or 2.\n\033[0m";
      cout<<"\033[1;33m\n\n\t\tEnter Choice (E.g. 1) : ";
   }
   cout<<"\033[0m";
   if(l_UserInput>0 && l_UserInput<3)
   {
     int p_UserChoice;
     p_UserChoice=l_UserInput;
     cout<<"\033[0m"; 
     return p_UserChoice;
   }
   else
   {
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[0m"; 
      return FAILED;
   }
}

int AccountUI :: getConfirm()
{
   int f1;
   int check=1;
   while(true)
   {
    cout<<"\033[1;33m\n\t\tEnter 1 to confirm your Registration: ";
    cin>>f1;
    if(f1==1)
      return f1;
    else
    {
      cin.clear();
      cin.ignore(50,'\n');
      if(check==1)
      {
        cout<<"\033[1;31m\n\n\t\tEnter only '1' to confirm your registration\033[0m";
        cout<<"\033[0m";
        check=0;
      }
      continue;
    }
   }
   cout<<"\033[0m";
   return f1;
}

long AccountUI::getTag_phno()
{
   string s1="";
   int l=0;
   while(l!=10)
   {
     cout<<"\033[1;33m\n\t\tTag Person Phone Number: ";
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
       cout<<"\033[0m";
       continue;
     }
     l=s1.length();
   }
   cout<<"\033[0m";
   long utph;
   utph=atol(s1.c_str());
   return utph;
}

void AccountUI :: displayRegSuc(string s)
{
    cout<<"\033[1;32m\n\t\tWelcome "<<s<<" !!!\n\t\tYou have Successfully registered To DIS.. \n\t\tPlease Login with registered Phnoe Number and Password\033[0m"; 
}

void AccountUI :: displayRegFail()
{
    cout<<"\033[1;31\n\t\tSorry User. You have already registered.\n\tPlease Login with your Credentials..\033[0m"; 
}

void AccountUI::displayUserInformation(Account a)
{
   system("clear");
   displaySuccess(a.getUname());
   cout<<"\033[1;36m\n\n\t**************************Account Information**************************\n\033[0m";
   cout<<"\033[1;35m\n\t\tName: "<<a.getUname();
   cout<<"\n\t\tPhno: "<<a.getUphno();
   cout<<"\n\t\tLocation: "<<a.getUlocation();
   cout<<"\n\t\tBlood Group: "<<a.getUblood_group();
   cout<<"\n\t\tDonor Status: "<<a.getStatus();
   if(a.getStatus()=='y')
   	cout<<"\n\t\tLast Date of Donation: "<<a.getUldod();
   cout<<"\n\t\tLast Login: "<<a.getLastLogin()<<"\033[0m";
   cout<<"\033[1;36m\n\n\t************************************************************************\n\033[0m";
}

void AccountUI::displayUpdateMenu()
{
   cout<<"\033[1;36m\n\n\t**************************Update Menu***********************************\n\033[0m";
   cout<<"\033[1;35m\n\t\t1.Name";
   cout<<"\n\t\t2.Location";
   cout<<"\n\t\t3.Donor Status";
   cout<<"\n\t\t4.Last Date of Donation";
   cout<<"\n\t\t5.Password\033[0m";
   cout<<"\033[1;33m\n\n\t************************************************************************\n\033[0m";
}

int AccountUI::getUpdateOption(int& p_UserChoice)
{
   int l_UserInput;
   cout<<"\033[1;33m\n\n\t\tChoose your option (E.g. 1) : ";
    
   while(!(cin>>l_UserInput))
   {  
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[1;31m\n\t\tEnter correct choice from 1 to 3.\n\033[0m";
      cout<<"\033[1;33m\n\n\t\tChoose your option (E.g. 1) : ";
   }
   cout<<"\033[0m";
   if(l_UserInput>0 && l_UserInput<6)
   {
     p_UserChoice=l_UserInput;
     cout<<"\033[0m"; 
     return SUCCESS;
   }
   else
   {
      cin.clear();
      cin.ignore(50,'\n');
      return FAILED;
   }
}

void AccountUI::displayNoTags(long s)
{
    cout<<"\033[1;31m\n\t\t"<<s<<" does not have any preferred Donors.Please use Search By BloodGroup and Location Option...!\033[0m";
}

void AccountUI::displaySuccess(string s)
{
    cout<<"\033[1;32m\n\n\t\tWelcome "<<s<<" \n\t\tYou Have Logged In Success Fully.\n\n\033[0m";
}

void AccountUI::displayUpdateSuccess()
{
    cout<<"\033[1;32m\n\n\t\tYou details have been Updated Successfully.\n\n\033[0m";
}

void AccountUI::displayValidate()
{
    cout<<"\033[1;32m\n\n\t\tYour Phone Number is Validated as New Phone Number.\n\n\t\tRegistration Successfull!!!\n\033[0m";
}

void AccountUI::displayNdonor(string s)
{
    cout<<"\033[1;31m\n\n\t\tSorry "<<s<<"\n\t\tYou cannot tag non-donors.\033[0m";
}

void AccountUI::displayTagSuc(string s,long p)
{
    cout<<"\033[1;32m\n\n\t\tDear "<<s<<"\n\t\tYou have tagged "<<p<<" Successfully.\033[0m";
}

void AccountUI::displayDTSuc(string s, long p)
{
    cout<<"\033[1;32m\n\n\t\tDear "<<s<<"\n\t\tYou have untagged "<<p<<" Successfully.\033[0m";
}

void AccountUI::displayDelete(string s)
{
    cout<<"\033[1;32m\n\n\t\tThank You "<<s<<"\n\t\tYou have Deleted Your Account Successfully.\033[0m";
}

void AccountUI::displayATagged(long p)
{
    cout<<"\033[1;31m\n\n\t\tYou have already tagged "<<p<<" .\033[0m";
}

void AccountUI::displayNewDonor()
{
    cout<<"\033[1;32m\n\n\t\tThe Phone Number you have entered is not registered with us.\n\t Please enter donor's details.\n\n";
}

void AccountUI::displayTags(vector<long> tags)
{
    cout<<"\033[1;32m\n\n\t\tList of Tagged people (Prefered Donors)..\n\n\033[0m";
    for(int i=0;i<tags.size();i++)
          cout<<"\033[1;32m\n\t\t"<<tags[i]<<"\t\t\n\033[0m";     
}

long AccountUI :: getRemoveph()
{
   string s1="";
   int l=0;
   while(l!=10)
   {
     cout<<"\033[1;33m\n\t\tEnter The Phone Number Which you want to Untag: ";
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
   long uph;
   uph=atol(s1.c_str());
   return uph;
}

void AccountUI :: displayTag(Account s,vector<Account> &tgl)
{
    cout<<"\033[1;36m\n\t\t**************************Your Information******************\n\033[0m";
    cout<<"\033[1;35m\n\t\t\tPhone Number : "<<s.getUphno()<<endl;
    cout<<"\n\t\t\tLocation : "<<s.getUlocation()<<endl<<"\033[0m\n";
    cout<<"\033[1;36m\n\t\t**************************************************************\n\033[0m";
    
    if(tgl.size()>0)
    {
      cout<<"\033[1;36m\n\t\t******************You are Tagged By Information*********************\n\n\033[0m";
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
      cout<<"\033[1;31m\t\tSorry ."<<s.getUphno()<<" You are not tagged by any persons. "<<s.getUlocation()<<"\n\033[0m";
    cout<<"\033[0m";
}

void AccountUI::dispdelsuc()
{
	cout<<"\033[1;33m\n\t\tYou have been Untagged  from his account Successfully.\n\033[0m";
}
