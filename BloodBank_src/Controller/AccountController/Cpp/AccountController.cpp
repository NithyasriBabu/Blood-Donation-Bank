#include "../../../AppClasses/Account/Include/Account.h"
#include "../../../UI/AccountUI/Include/AccountUI.h"
#include "../../../Model/Include/DB.h"
#include "../../../GlobalDefs/Include/GlobalDefs.h"
#include "../../../ExceptionClasses/SqlError/Include/SqlError.h"
#include "../Include/AccountController.h"
#include<vector>

int AccountController :: initRegister()
{
   Account aobj;
   int t_confirm,cng;
   aobj.setUname(AccountUI::getUname());
   aobj.setUpass(AccountUI::getUpass());
   aobj.setUblood_group(AccountUI::getUblood_group());
   aobj.setUphno(AccountUI::getUphno());
   aobj.setUlocation(AccountUI::getUlocation()); 
   aobj.setStatus(AccountUI::getStatus());
   if(aobj.getStatus()=='y')
      aobj.setUldod(AccountUI::getUldod());
   else
      aobj.setUldod(string("01-JAN-1990"));
   t_confirm=AccountUI::getConfirm();
   if(t_confirm==SUCCESS)
   {
      try
      {
      	cng=AccountController::initValidate(aobj); //DB::dbValidate(aobj);
        if(cng==1)
        {
      	  DB::dbRegister(aobj);
      	  AccountUI::displayRegSuc(aobj.getUname());
      	  return SUCCESS;
        }      
      }
      catch(SqlError sqlerror)
      {
      	MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
      	return FAILED;  
      }
   }
}

int AccountController :: initValidate(Account &a)
{   
   int cnt=0;
   try
   {
       cnt=DB::dbValidate(a);
       if(cnt==1)
         AccountUI::displayValidate();
       return SUCCESS;
   }
   catch(SqlError sqlerror)
   {
      MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
      return FAILED;  
   }
}

int AccountController :: initLogin(Account &a)
{
   int i;
   i=AccountUI::LoginOption();
   if(i==1)
   {
    a.setUphno(AccountUI::getUphno());
    a.setUpass(AccountUI::getUpass());
   }
   if(i==2)
   {
      initFlogin(a);
   }
   try
   {
      DB::dbCheckLogin(a);
      AccountUI::displaySuccess(a.getUname());
      AccountUI::displayUserInformation(a);
      return SUCCESS;
   }
   catch(SqlError sqlerror)
   {
      MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
      return FAILED;        
   }
}

void AccountController :: initFlogin(Account &a)
{
  string ar,b;
  fstream ts;
  int i=0;
  string f;
  f=AccountUI::getDetails();

  ts.open(f.c_str(),ios::in);
  if(ts.is_open())
  {
   cout<<"File Opened"<<endl;
   while(!ts.eof())
   {
    ts>>ar>>b;
    cout<<"First Line Read as "<<ar<<endl;
    cout<<"Second Line Read as "<<b<<endl;
    cout<<"I'm Stuck in while"<<endl;
   }
  }
  ts.close();
  
  a.setUphno(atol(ar.c_str()));
  a.setUpass(b);
}

int AccountController :: initTag(Account &a)
{
 int ct;
   a.setTag_phno(AccountUI::getTag_phno());
   try
   {      
     ct=DB::dbValidateTag(a);
     if(ct==1)
     {
         DB::dbaddTag(a);
         AccountUI::displayTagSuc(a.getUname(),a.getTag_phno());
     }
     else if(ct==5)
         AccountUI::displayNdonor(a.getUname());
     else if(ct==3)
	 AccountUI::displayATagged(a.getTag_phno());
     else
     {
         AccountUI::displayNewDonor();
         Account aobj;
         aobj.setUname(AccountUI::getUname());
         aobj.setUpass(AccountUI::getUpass());
         aobj.setUblood_group(AccountUI::getUblood_group());
         aobj.setUphno(a.getTag_phno());
         aobj.setUlocation(AccountUI::getUlocation()); 
         aobj.setStatus('y');
         aobj.setUldod(AccountUI::getUldod());
         DB::dbRegister(aobj);
      	 DB::dbaddTag(a);
         AccountUI::displayTagSuc(aobj.getUname(),a.getTag_phno());
     }
      
    }
    catch(SqlError sqlerror)
    {
       MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
       return FAILED;  
    }

}

int AccountController :: initUntag(Account &a)
{
  try
 {
   if(DB::dbCheckTags(a)==FAILED)
       MainUI :: displayUserMessage("\033[1;31m\n\t\tYou have not tagged anyone yet.\n\t\tYou can start Tagging now\n\n\033[0m");
   else
   {
      a.setTag_phno(AccountUI::getTag_phno());
      DB::dbUntag(a);
      AccountUI::displayDTSuc(a.getUname(),a.getTag_phno());
   }
  }
  catch(SqlError sqlerror)
  {
    MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
    return FAILED;  
  }
}

int AccountController :: initUpdate(Account &a)
{
   int u_choice;
   string n_name,n_loc,n_date,pass;
   char s;
   AccountUI::displayUserInformation(a);
   AccountUI::displayUpdateMenu();
   if((AccountUI::getUpdateOption(u_choice) == FAILED)) // For Getting the option from the registered user.
   {
	MainUI :: displayUserMessage("\033[1;31m\n\tInvalid input. Please choose the choice from 1 to 5\n\n\033[0m");
   }
   else
   {   
	try
	{
	  switch(u_choice)
	  {
		case 1://name		
			n_name=AccountUI::getUname();
			DB::dbUpdateName(a,n_name);
			a.setUname(n_name);
			break;
		case 2://location
			n_loc=AccountUI::getUlocation();
			DB::dbUpdateLocation(a,n_loc);
			a.setUlocation(n_loc);
			break;
		case 3://Donor Status
			s=AccountUI::getStatus();
			DB::dbUpdateStatus(a,s);
			a.setStatus(s);
			break;
		case 4://last dod
			n_date=AccountUI::getUldod();
			DB::dbUpdateLdod(a,n_date);
			a.setUldod(n_date);
			break;
		case 5://password
			pass=AccountUI::getUpass();
			DB::dbUpdatePass(a,pass);
			a.setUpass(pass);
			break;
		default:
			MainUI::displayUserMessage("\033[1;31m\n\n\tYou have choosen an invalid choice. Try Again..\n\n\033[0m");
	  }
	  AccountUI::displayUpdateSuccess();
	  return SUCCESS;
        }
        catch(SqlError sqlerror)
	{
	   MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
           return FAILED;  
	}
   }
}

int AccountController :: initDelete(Account &a)
{  
    string pass;
    pass=AccountUI::getUpass();
    try
    {
      DB::dbDelete(a,pass);
      AccountUI::displayDelete(a.getUname());
      return SUCCESS;
    }
    catch(SqlError sqlerror)
    {
      MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
      return FAILED;  
    }
}

int AccountController :: initView_Tags(Account &a)
{
    vector<long> tags;
    try
    {
      DB::dbView_Tags(a,tags);
      AccountUI::displayTags(tags);
      return SUCCESS;
     }
     catch(SqlError sqlerror)
     {
      MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
      return FAILED;  
     }
}

int AccountController :: initRtag(Account &a)
{
    vector<Account> al;
    try
    {   
   
      DB::dbFetch(a,al);
      if(al.size()==0)
      {
	MainUI::displayUserMessage("\033[1;31m\n\t\tYou are not tagged to Anyone...\n\033[0m");
	return FAILED;
      }
      else
	  AccountUI::displayTag(a,al);

     long ph;long tp;

     ph=AccountUI :: getRemoveph();
     tp=a.getUphno();
      
     DB ::dbDel(ph,tp);
             
      AccountUI::dispdelsuc();
      return SUCCESS;
    }
    catch(SqlError sqlerror)
    {
       MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
       return FAILED;  
    }
}