#include "../Include/AdminController.h"
#include "../../../UI/AdminUI/Include/AdminUI.h"
#include "../../../GlobalDefs/Include/GlobalDefs.h"
#include "../../../AppClasses/Hospital/Include/Hospital.h"
#include "../../../UI/HospitalUI/Include/HospitalUI.h"
#include "../../../Model/Include/DB.h"
#include<vector>

int AdminController:: initAdmin()
{
        string u=AdminUI::getName();
	string p=AdminUI::getPass();
	if(u=="Dastan" && p=="tamina")
	{
	   AdminUI::displayLogin();
	   return SUCCESS;
	}
	else
	   return FAILED;
}

void AdminController :: initOperation()
{
	vector<Hospital> h;
	Hospital ho;

	int i=AdminUI::displayMenu();
	switch(i)
	{
		case VIEWH:
    		    try
      		    {
			DB::dbView_Hos(h);
      			HospitalUI::displayHospitals(h);
     		    }
     		    catch(SqlError sqlerror)
     		    {
		      MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
	            }
		    break;

		case ADDH:
			ho.setId(HospitalUI::getId());
			ho.setName(HospitalUI::getName());
			ho.setLocation(HospitalUI::getLocation());
			HospitalUI::getDates(ho);
			HospitalUI::getStock(ho);
			try
			{
				DB::dbAdd_Hos(ho);
				MainUI::displayUserMessage("\033[1;33m\n\t\tHospital Added Successfully\n\033[0m");
			}
			catch(SqlError sqlerror)
     		    	{
		      		MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
	            	}
			break;

		default:
			MainUI::displayUserMessage("\033[1;31m\n\n\tYou have choosen an Invalid Choice...\n\t\t Please  Try Again..\n\n\033[0m");
			break;
	}
	
}
