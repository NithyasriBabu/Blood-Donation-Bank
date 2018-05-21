#ifndef _DB_H_
#define _DB_H_

#include <iostream>
using namespace std;
#include "../../AppClasses/Account/Include/Account.h"
#include "../../AppClasses/Seeker/Include/Seeker.h"
#include "../../AppClasses/Hospital/Include/Hospital.h"
#include <vector>

class DB
{
    static string m_dbUsername;
    static string m_dbPassword ;
    static bool m_DbConnected;

public:
    static void dbConnect();
    static void dbDisconnect();
    static void initializeDBConnection(string, string);
    static void dbCheckLogin(Account&);
    static void dbRegister(Account);
    static int dbValidate(Account);
    static void dbaddTag(Account);
    static int  dbValidateTag(Account);

    static int dbDateCon(string);

    static void dbDelete(Account,string);
    static void dbFindUser(long,Account&);

    static void dbFindTags(Seeker,vector<Account>&);
    static void dbFindDonors(Seeker,vector<Account>&);

    static void dbUpdateName(Account,string);
    static void dbUpdateLocation(Account,string);
    static void dbUpdateStatus(Account,char);
    static void dbUpdateLdod(Account,string);
    static void dbUpdatePass(Account,string);
    static void dbUntag(Account);

    static string dbNow();

    static void dbView_Tags(Account,vector<long>&);
    static int dbCheckTags(Account);

    static void dbView_Hos(vector<Hospital>&);
    static void dbAdd_Hos(Hospital);

    static void dbFetch(Account&,vector<Account> &);
    static int dbDel(long,long);


};

#endif
