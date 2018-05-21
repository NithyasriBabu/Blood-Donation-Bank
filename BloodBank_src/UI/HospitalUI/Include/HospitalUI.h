#ifndef _HOSPITALUI_H_
#define _HOSPITALUI_H_

#include <iostream>
#include<cstdlib>
#include<iomanip>
#include<vector>
using namespace std;

#include "../../MainUI/Include/MainUI.h"
#include "../../../AppClasses/Hospital/Include/Hospital.h"

class HospitalUI : public MainUI
{
   public:
   static string getName();
   static string getLocation();
   static int getId();
   static void getDates(Hospital&);
   static void getStock(Hospital&);
   static void displayHospitals(vector<Hospital>);

};

#endif
