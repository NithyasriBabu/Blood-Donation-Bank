#ifndef _SQL_ERROR_H_
#define _SQL_ERROR_H_

#include <iostream>
using namespace std;

class SqlError 
{
  int m_SqlErrorCode;
  string m_SqlErrorMessage;
  string m_ApplicationErrorMessage;
  
  public:
  SqlError(int, string, string);
  int getSqlErrorCode();
  string getSqlErrorMessage();
  string getApplicationErrorMessage();
};

#endif
