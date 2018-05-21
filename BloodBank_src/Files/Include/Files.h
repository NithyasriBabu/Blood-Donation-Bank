#ifndef _FILES_H_
#define _FILES_H_

#include "../../GlobalDefs/Include/GlobalDefs.h"

#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class Files
{
  public:
   static int openFileWrite(char*,fstream);
   static void closeFile(fstream);
   static void writeData(string,fstream);
   static void readData(string&,fstream);
};

#endif
