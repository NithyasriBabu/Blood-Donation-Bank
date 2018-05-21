#include "../Include/AdminUI.h"

string AdminUI :: getName()
{
   string name;
   static int f=0;
   do
   {
     cout<<"\033[1;33m\n\t\tAdmin UserName : ";
     cin.ignore();
     getline(cin,name);
     int asc;
     for(int i=0;i<name.length();i++)
     {
      asc=int(name[i]);
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
   return name;
}

string AdminUI :: getPass()
{
   string ups;
   cout<<"\033[1;33m";
   char *up=getpass("\n\t\tPassword  :");
   ups=string(up);
   cout<<"\033[0m";
   return ups;
}

void AdminUI :: displayLogin()
{
    cout<<"\033[1;32m\n\n\t\tAdmin Logged In Successfully.\n\n\033[0m";
}

int AdminUI :: displayMenu()
{
   cout<<"\033[1;36m\n\n\t**************************Admin Menu***********************************\n\033[0m";
   cout<<"\033[1;35m\n\t\t1.Add Hosplitals";
   cout<<"\n\t\t2.View Hospitals\033[0m";
   cout<<"\033[1;33m\n\n\t************************************************************************\n\033[0m";

   int l_UserInput;
   cout<<"\033[1;33m\n\t\tEnter Choice (E.g. 1) : ";
    
   while(!(cin>>l_UserInput))
   {  
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[1;31m\n\t\tEnter correct choice 1 to 2.\n\033[0m";
      cout<<"\033[1;33m\n\n\t\tEnter Choice (E.g. 1) : ";
   }
   cout<<"\033[0m";
   if(l_UserInput>0 && l_UserInput<3)
   {
     cout<<"\033[0m"; 
     return l_UserInput;
   }
   else
   {
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[0m"; 
      return 0;
   }
}

