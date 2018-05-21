#include "../Include/SqlError.h"

SqlError::SqlError(int p_SqlErrorCode, string p_SqlErrorMessage, string p_ApplicationErrorMessage)
{
  this->m_SqlErrorCode = p_SqlErrorCode;
  this->m_SqlErrorMessage = p_SqlErrorMessage;
  this->m_ApplicationErrorMessage = p_ApplicationErrorMessage;
}

int SqlError :: getSqlErrorCode()
{
  return m_SqlErrorCode;
}

string SqlError :: getSqlErrorMessage()
{
  return m_SqlErrorMessage;
}

string SqlError :: getApplicationErrorMessage()
{
  return m_ApplicationErrorMessage;
}
