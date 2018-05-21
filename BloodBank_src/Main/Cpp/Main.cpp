#include "../Include/Main.h"
#include "../../GlobalDefs/Include/GlobalDefs.h"
#include "../../Model/Include/DB.h"
#include "../../Controller/AccountController/Include/AccountController.h"
#include "../../Controller/SeekerController/Include/SeekerController.h"
#include "../../Controller/AdminController/Include/AdminController.h"
#include "../../UI/AccountUI/Include/AccountUI.h"
#include "../../UI/SeekerUI/Include/SeekerUI.h"
#include "../../UI/MainUI/Include/MainUI.h"
#include "../../ExceptionClasses/SqlError/Include/SqlError.h"
#include "../../Utility/Include/Utility.h"
#include <stdlib.h>

int main()
{
  Account account;

  int m_Choice=0;
  int u_Choice=0;
  int l_Choice=0;
  int cont=1;

  DB::initializeDBConnection((string)"hcu08orauser3d@unixdb",(string)"tcshyd");
  
  try
  {
     DB::dbConnect(); // Connecting to DB. If DB connection failed, catch block will handle
     do
     {
	MainUI :: displayMainPage(); // Showing Main Menu
	if(MainUI::getMainMenuOption(m_Choice)==FAILED)
	{
	   MainUI::displayUserMessage("\033[1;31m\n\t\tInvalid Input\n\n\t\tPlease Choose From 1 to 4\n\n\033[0m");
	}
        else
	{
	   switch(m_Choice)
	   {
		case ABOUT:
			MainUI::displayAboutDIS();
			break;
		case CONTACT:
			MainUI::displayContactDIS();
			break;
		case ENTER:
			MainUI::displayUserMenu();
			if((MainUI::getUserOption(l_Choice) == FAILED)) // For Getting the option from the user
          		{
		            MainUI :: displayUserMessage("\033[1;31m\n\tInvalid input. Please choose the choice from 1 to 4\n\n\033[0m");
          		}
			else
			{
			    switch(l_Choice)
		  	    {
				case REGISTER:
					if (AccountController::initRegister() == FAILED) // Initiating for Customer Registration
						MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m");
					break;

				case LOGIN:
					 if(AccountController::initLogin(account) == FAILED) // Initiating for User Login
						MainUI::displayUserMessage("\033[1;31m\n\t\tAre You a Registered User??\n\t\tIf Yes,Please Enter Correct Password.\n\t\tIf Not, Please Register with Us.\n\033[0m");
					 else
					 {
					      do
					      {
						static int cnt=0;
						int cho=0;

						AccountUI::displayUserInformation(account);

						MainUI :: displayMenu(); // Showing the Menu of Registered User 

						if((MainUI::getLoginOption(l_Choice) == FAILED)) // For Getting the option from the registered user.
							MainUI :: displayUserMessage("\033[1;31m\n\t\tPlease enter options only from from 1 to 4\n\n\033[0m");
						else
   						{
							switch(l_Choice)
							{
								case TAGGING :
									do
									{
									   if (AccountController::initTag(account) == FAILED) // Initiating for tagging
                                                             		   {
										MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m");
                                                                		break;
							     		   }
                                                             		   cnt++;
							     		   cho= MainUI::getTagChoice();
                                                          		}while(cho==SUCCESS);
                                                          	break;

								case UPDATE :
									   if (AccountController::initUpdate(account) == FAILED) // Initiating for updating the details
                                                              			MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m");
                                                   		break;
						
				   				case UNTAG :
									   if (AccountController::initUntag(account) == FAILED) // Initiating for untagging donors
                                                              			MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m");
                                                   		break;

								case DELETE :
									   if (AccountController::initDelete(account) == FAILED) // Initiating for Delete Account
										MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m");
                                                   		break;
				  
								case VIEW_TAGS :
                                                                           if (AccountController::initView_Tags(account) == FAILED) // Inititing for viewing tagged persons
                                                                                MainUI::displayUserMessage("\033[1;31m\n\t\tYou can start tagging now... \n\t\t\n\033[0m"); 
                                                                break;

								case UNTAGME :
                                                                           if (AccountController::initRtag(account) == FAILED) // Initiating for Untag Ny Tagged Account
										MainUI::displayUserMessage("\033[1;31m\n\t\tSorry Try Untagging only if You are tagged\n\n\033[0m");
                                                   		break;

								case LOGOUT:
									break;

								default:  
									MainUI::displayUserMessage("\033[1;31m\n\t\tYou have choosen an Invalid Choice...\n\t\t Please Try Again..\n\n\033[0m");
							}

						}
						if(l_Choice==DELETE || l_Choice==LOGOUT)
							break;
 
					     }while(MainUI::toContinueLogin());

						if(l_Choice!=DELETE || l_Choice==LOGOUT)
						     MainUI::displayLogout(account.getUname());
					}
					break;
 
				case SEARCHBYPHONE   :
					if(SeekerController::initSearchByPhone() == FAILED) // Initiating donor search by phone  
						MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m");
				        break;
        
				case SEARCHBYBGANDLOC   :
					if(SeekerController::initSearchByBgALoc() == FAILED) // Initiating donor search by blood group and location
						MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m"); 
             				break;

				case ADMIN:
					if(AdminController::initAdmin() == FAILED)
						MainUI::displayUserMessage("\033[1;31m\n\t\tSorry for the Failure.. \n\t\tPlease try again...\n\033[0m");
					else
						AdminController::initOperation();
					break;

				default:  
					MainUI::displayUserMessage("\033[1;31m\n\n\tYou have choosen an Invalid Choice...\n\t\t Please  Try Again..\n\n\033[0m");

				} // close switch
			} //else
			break;

		case EXIT:
			MainUI::displayUserMessage("\033[1;33m\n\n\t\tThank you for using the Application...\n\n\n\033[0m");
			break;


		default:
			MainUI::displayUserMessage("\033[1;31m\n\n\tYou have entered Invalid Choice...\n\t\t Please  Try Again..\n\n\033[0m");
	      }//close switch

	   }//close else

		if(m_Choice==EXIT)
			break;

	}while(MainUI::toContinue());

     } //close try

     catch(SqlError sqlerror)
     {
	MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
     }
}
