#ifndef _ADMINCONTROLLER_H_
#define _ADMINCONTROLLER_H_
#include "../../../ExceptionClasses/SqlError/Include/SqlError.h"

#include<string.h>

class AdminController
{
   public:
	static int initAdmin();
	static void initOperation();
};

#endif
