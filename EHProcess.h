#pragma once
#include <iostream>
#include <string>
using namespace std;

class EHProcess
{
  string pname;
  const int tjob;
  const int cjob;
  int ntjob;
  int ncjob;
  public:
  EHProcess(string pname, int tjob, int cjob);
  void IdleToReady();
  int Running();
  void EndProgram();
};