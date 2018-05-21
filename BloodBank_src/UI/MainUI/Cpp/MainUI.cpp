#include "../Include/MainUI.h"
#include "../../../GlobalDefs/Include/GlobalDefs.h"
#include "../../../Utility/Include/Utility.h"
#include <stdlib.h>

void MainUI :: displayUserMessage(string p_message)
{
    cout<<setw(20)<<endl<<p_message;
}

int MainUI::getUserOption(int& p_UserChoice)
{
   int l_UserInput;
   cout<<"\033[1;33m\n\n\t\tChoose your option (E.g. 1) : ";
   while(!(cin>>l_UserInput))
   {  
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[1;31m\n\t\tEnter correct choice from 1 to 5.\n\033[0m";
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
      cout<<"\033[0m";
      return FAILED;
   }
}

int MainUI::getLoginOption(int& p_UserChoice)
{
   int l_UserInput;
   cout<<"\033[1;33m\n\n\t\tChoose your option (E.g. 1) : ";
   while(!(cin>>l_UserInput))
   {  
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[1;31m\n\t\tEnter correct choice from 1 to 7.\n\033[0m";
      cout<<"\033[1;33m\n\n\t\tChoose your option (E.g. 1) : ";
    }
   cout<<"\033[0m";
   
   if(l_UserInput>0 && l_UserInput<8)
   {
     p_UserChoice=l_UserInput; 
     cout<<"\033[0m";
     return SUCCESS;
   }
  else
   {
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[0m";
      return FAILED;
   }
}

void MainUI::displayLogout(string s)
{
   cout<<"\033[1;32m\n\t\tThank You for using DIS "<<s<<"\n\t\tYou Have Logged out Successfully\n\033[0m";
}

int MainUI::getMainMenuOption(int& p_UserChoice)
{
   int l_UserInput;
   
   cout<<"\033[1;33m\n\n\t\tChoose your option (E.g. 1) : ";
   
   while(!(cin>>l_UserInput))
   {  
      cin.clear();
      cin.ignore(50,'\n');
      cout<<"\033[1;31m\n\t\tEnter correct choice from 1 to 4.\n\033[0m";
      cout<<"\033[1;33m\n\n\t\tChoose your option (E.g. 1) : ";
   }
   cout<<"\033[0m";
   
   if(l_UserInput>0 && l_UserInput<5)
   {
     p_UserChoice=l_UserInput;
     return SUCCESS;
   }
   else
   {
      cin.clear();
      cin.ignore(50,'\n');
      return FAILED;
   }
   cout<<"\033[0m";
}


int MainUI::toContinue()
{
   char l_UserInput;
   cout<<"\033[1;33m\n\n\t\tContinue to Main Menu? (Y/N) : ";
   while(true)
   {
     cin>>l_UserInput;
     if ((l_UserInput=='Y')||(l_UserInput=='y'))
     { 
       cout<<"\033[0m";
       return SUCCESS;
     }
     else if((l_UserInput=='N')||(l_UserInput=='n'))
     {
	cout<<"\033[0m";
        return FAILED;
     }
     else
     {
       cin.clear();
       cin.ignore(50,'\n');
       cout<<"\033[1;31m\n\t\tEnter only (Y/N)\033[0m";
       cout<<"\033[1;33m\n\n\t\tContinue to Main Menu? (Y/N) : ";
       continue;
     }
   }
}

int MainUI::toContinueLogin()
{
   char l_UserInput;
   cout<<"\033[1;33m\n\n\t\tContinue to Login Menu? (Y/N) : ";
   while(true)
   {
     cin>>l_UserInput;
     if ((l_UserInput=='Y')||(l_UserInput=='y'))
     { 
	cout<<"\033[0m";
        return SUCCESS;
     }
     else if((l_UserInput=='N')||(l_UserInput=='n'))
     {
	cout<<"\033[0m";
        return FAILED;
     }
     else
     {
       cin.clear();
       cin.ignore(50,'\n');
       cout<<"\033[1;31m\n\t\tEnter only (Y/N)\033[0m";
       cout<<"\033[1;33m\n\n\t\tContinue to Login Menu? (Y/N) : ";
       continue;
     }
     cout<<"\033[0m";
   }
}

void MainUI::displayMainPage()
{
   system("clear");
   cout<<"\033[1;36m\n\n\n\t*******************************WELCOME TO THE DONOR INFORMATION SYSTEM********************************\n\033[0m";
   cout<<"\033[1;35m\n\t\t1.About DIS";
   cout<<"\n\t\t2.Contact Information of DIS";
   cout<<"\n\t\t3.Enter into DIS";
   cout<<"\n\t\t4.Exit DIS\033[0m";
   cout<<"\033[1;36m\n\n\t******************************************************************************************************\n\033[0m";
}

void MainUI::displayUserMenu()
{
   system("clear");
   cout<<"\033[1;32m\n\n\tWelcome User... Please Choose an Option From the Below Options... \n\n\n\033[0m";
   cout<<"\033[1;36m\n\n\t**********************DONOR INFORMATION SYSTEM*******************\n\033[0m";
   cout<<"\033[1;35m\n\t\t1.Register";
   cout<<"\n\t\t2.Login";
   cout<<"\n\t\t3.Search By Phone Number";
   cout<<"\n\t\t4.Search By Blood Group And Location";
   cout<<"\n\t\t5.Admin Operations\n\033[0m";
   cout<<"\033[1;36m\n\n\t*****************************************************************\n\033[0m";
}

void MainUI :: displayMenu()
{
    cout<<"\033[1;36m\n\n\t*********************Select Option to Continue*************************\n\n\033[0m";
    cout<<"\033[1;35m\n\t\t1.Tag Person";
    cout<<"\n\t\t2.Untag Person";
    cout<<"\n\t\t3.Update Details";
    cout<<"\n\t\t4.Delete Account";
    cout<<"\n\t\t5.View tags";
    cout<<"\n\t\t6.Untag from Others";
    cout<<"\n\t\t7.Logout\n\033[0m";
}

int MainUI::getTagChoice()
{
   char l_UserInput;
   cout<<"\033[1;33m\n\n\t\tDo You Want to Tag Again [Y/N]:  ";
   while(true)
   {
     cin>>l_UserInput;
     if ((l_UserInput=='Y')||(l_UserInput=='y'))
     { 
       cout<<"\033[0m";
       return SUCCESS;
     }
     else if((l_UserInput=='N')||(l_UserInput=='n'))
     {
        cout<<"\033[0m";
        return FAILED;
     }
     else
     {
       cin.clear();
       cin.ignore(50,'\n');
       cout<<"\033[1;31m\n\t\tEnter only (Y/N)\033[0m";
       cout<<"\033[1;33m\n\n\t\tContinue to Main Menu? (Y/N) : ";
       continue;
     }
      cout<<"\033[0m";
   }
}

void MainUI::displayAboutDIS()
{
   string dis="\033[1;32m\n\n\t\tThis is a Donor Information System. It consists of the database of the donors who are willing to donate blood.\n";
   dis+="\t\tAlso there are a list of users who have registered to seek for donors. The system helps anyone to get information about donors when required.\n\033[0m";
   MainUI::displayUserMessage(dis);
}

void MainUI::displayContactDIS()
{
   cout<<"\033[1;32m\n\n\t\tContact details will be Uploaded shortly..\033[0m"<<endl<<endl;
}