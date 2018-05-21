#include "../Include/Files.h"
#include<fstream>
using namespace std;

int Files :: openFileWrite(char* filename,fstream wf)
{
    wf.open(filename,ios::out|ios::trunc);
    if(wf.is_open())
      return SUCCESS;
    else
      return FAILED;
}

void Files :: closeFile(fstream wf)
{
    wf.close();
}

void Files :: writeData(string data,fstream wf)
{
    data=data+"\n";
    wf<<data;
}

void Files :: readData(string &data,fstream wf)
{
}
