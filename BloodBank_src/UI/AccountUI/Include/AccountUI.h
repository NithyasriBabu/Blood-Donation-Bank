#ifndef _ACCOUNTUI_H_
#define _ACCOUNTUI_H_

#include <iostream>
#include<cstdlib>
#include<iomanip>
#include<vector>
using namespace std;

#include "../../MainUI/Include/MainUI.h"
#include "../../../AppClasses/Account/Include/Account.h"

class AccountUI : public MainUI
{
   public:
   static string getUname();
   static string getUpass();
   static long  getUphno();
   static string getUlocation();
   static string getUblood_group();
   static string getUldod();
   static char getStatus();
   static int getConfirm();
   static long getTag_phno();

   static int LoginOption();
   static string getDetails();

   static void displayRegSuc(string);
   static void displayRegFail();

   static void displayUserInformation(Account);

   static void displayUpdateMenu();
   static int getUpdateOption(int&);

   static void displayNoTags(long);
   static void displaySuccess(string);
   static void displayUpdateSuccess();
   static void displayValidate();
   static void displayNdonor(string);
   static void displayTagSuc(string,long);
   static void displayDTSuc(string,long);
   static void displayDelete(string);
   static void displayATagged(long);
   static void displayNewDonor();
   static void displayTags(vector<long>);

   static long getRemoveph();
   static void displayTag(Account,vector<Account> &);
   static void dispdelsuc();



};

#endif
