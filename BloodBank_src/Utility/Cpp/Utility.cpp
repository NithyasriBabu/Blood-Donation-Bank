#include "../Include/Utility.h"
#include "../../GlobalDefs/Include/GlobalDefs.h"
#include <sstream>

string Utility::toString(long p_Number)
{
 string l_Result;          // string which will contain the result
 ostringstream l_Convert;  // stream used for the conversion
 l_Convert << p_Number;      // insert the textual representation of 'Number' in the characters in the stream
 l_Result = l_Convert.str(); 
 return l_Result;
}
