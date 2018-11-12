#include "EHProcess.h"

EHProcess::EHProcess(string pname, int tjob, int cjob):tjob(tjob), cjob(cjob)
{
  this->pname = pname;
}

void EHProcess::IdleToReady()
{
  cout << pname << " start" << endl;
  ntjob = tjob;
}

int EHProcess::Running()
{
  ncjob = cjob;
  for( ; ntjob && ncjob; ntjob--, ncjob--) {
    cout << pname << " ";
  }
  cout << endl;
  return ntjob;
}

void EHProcess::EndProgram()
{
  cout << pname << " End" << endl;
}