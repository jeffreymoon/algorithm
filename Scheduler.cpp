#include "Scheduler.h"

Scheduler::Scheduler()
{
  Init();
  Simulation();
}

void Scheduler::Init()
{
  hard_disk.push_back(new EHProcess("A", 30, 5));
  hard_disk.push_back(new EHProcess("B", 24, 6));
  hard_disk.push_back(new EHProcess("C", 25, 4));

  miter seek = hard_disk.begin();
  miter end = hard_disk.end();
  EHProcess *pro = 0;

  for(; seek != end; ++seek) {
    pro = *seek;
    rq.push(pro);
    pro->IdleToReady();
  }
}

Scheduler::~Scheduler()
{
  Ending();
}

void Scheduler::Ending()
{
  miter seek = hard_disk.begin();
  for( ; seek != hard_disk.end(); ++seek) {
    delete(*seek);
  }
}

void Scheduler::Simulation()
{
  EHProcess *process = 0;
  int job = 0;
  while(!(rq.empty())) {
    process = rq.front();
    rq.pop();
    job = process->Running();
    if(job) {
      rq.push(process);
    } else {
      process->EndProgram();
    }
  }
}