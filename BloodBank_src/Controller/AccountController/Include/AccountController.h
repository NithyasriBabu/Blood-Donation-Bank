#ifndef _ACCOUNTCONTROLLER_H_
#define _ACCOUNTCONTROLLER_H_

#include<fstream>

class AccountController
{
   public:
   static int initRegister();
   static int initValidate(Account &);
   static int initLogin(Account &);
   static int initDelete(Account &);
   static int initUntag(Account &);
   static int initTag(Account &);
   static int initUpdate(Account &);
   static int initView_Tags(Account &);
   static void initFlogin(Account &);
   static int initRtag(Account &);
};

#endif
