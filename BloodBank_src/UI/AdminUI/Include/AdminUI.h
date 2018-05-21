#ifndef _ADMINUI_H_
#define _ADMINUI_H_

#include <iostream>
using namespace std;
#include "../../MainUI/Include/MainUI.h"
#include "../../../Utility/Include/Utility.h"
#include<string.h>

class AdminUI : public MainUI
{
   public:
   static string getName();
   static string getPass();
   static void displayLogin();
   static int displayMenu();
};

#endif
