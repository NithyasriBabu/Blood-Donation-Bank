#ifndef _SEEKERUI_H_
#define _SEEKERUI_H_

#include <iostream>
using namespace std;
#include "../../MainUI/Include/MainUI.h"
#include "../../../AppClasses/Account/Include/Account.h"
#include "../../../AppClasses/Seeker/Include/Seeker.h"
#include "../../../Utility/Include/Utility.h"
#include "../../../Files/Include/Files.h"
#include<vector>
#include<cstdlib>
#include<string.h>
#include<fstream>

class SeekerUI : public MainUI
{
   public:
   static long getPhno();
   static string getLocation();
   static string getBloodGroup();
   static void displayDonors(Seeker,vector<Account>&);
   static void generateDonorsReport(Seeker s,vector<Account>&);
   static void displayTags(Seeker,vector<Account>&);
   static void generateTagsReport(Seeker, vector<Account>&);
   static void displayNoTags(long);
   static void displayTagReportSuccess(long,string);
   static void displayDonorReportSuccess(string,string);
};

#endif
