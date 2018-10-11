#pragma once
#include <vector>
#include <queue>
using namespace std;
#include "EHProcess.h"

using Memory = vector<EHProcess*>;
using ReadyQueue = queue<EHProcess*>;
using miter = Memory::iterator;

class Scheduler
{
  Memory hard_disk;
  ReadyQueue rq;
  public:
  Scheduler();
  virtual ~Scheduler();
  private:
  void Init();
  void Simulation();
  void Ending();
};