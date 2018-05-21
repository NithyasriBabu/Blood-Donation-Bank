#include "../Include/SeekerController.h"
#include "../../../AppClasses/Seeker/Include/Seeker.h"
#include "../../../AppClasses/Account/Include/Account.h"
#include "../../../GlobalDefs/Include/GlobalDefs.h"
#include "../../../UI/SeekerUI/Include/SeekerUI.h"
#include "../../../UI/AccountUI/Include/AccountUI.h"
#include "../../../Model/Include/DB.h"
#include "../../../ExceptionClasses/SqlError/Include/SqlError.h"
#include <vector>


int SeekerController :: initSearchByPhone()
{
    Seeker sbp;
    vector<Account> taglist;

    sbp.setPhno(SeekerUI::getPhno());
    sbp.setLocation(SeekerUI::getLocation());

    try
    {
        DB::dbFindTags(sbp,taglist);
	if(taglist.size()==0)
	  AccountUI::displayNoTags(sbp.getPhno());
	else
	{
	  SeekerUI::displayTags(sbp,taglist);
	  SeekerUI::generateTagsReport(sbp,taglist);
	} 
        return SUCCESS;
    }
    catch(SqlError sqlerror)
    {
        MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
        return FAILED;
    }
}

int SeekerController :: initSearchByBgALoc()
{
    Seeker sbl;
    vector<Account> lists;

    sbl.setBlood_group(SeekerUI::getBloodGroup());
    sbl.setLocation(SeekerUI::getLocation());
    
    try
    {
	DB::dbFindDonors(sbl,lists);
	SeekerUI::displayDonors(sbl,lists);
	SeekerUI::generateDonorsReport(sbl,lists);
	return SUCCESS;
    }
    catch(SqlError sqlerror)
    {
	MainUI::displayUserMessage(sqlerror.getApplicationErrorMessage());
	return FAILED;
    }
}
