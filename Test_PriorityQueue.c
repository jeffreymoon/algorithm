#include "PriorityQueue.h"

void PrintNode(PQNode* Node)
{
  printf("Work name : %s (Priority: %d)\n", Node->Data, Node->Priority);
}

int main(void)
{
  PriorityQueue* PQ = PQ_Create(3);
  PQNode Popped;

  PQNode Nodes[7] = {
    {34, (void*)"Coding"},
    {12, (void*)"Meeting with customor"},
    {87, (void*)"Making a cup of coffee"},
    {45, (void*)"Writing a document"},
    {35, (void*)"Dubugging"},
    {66, (void*)"Cleaning my teeth"}
  };

  PQ_Enqueue(PQ, Nodes[0]);
  PQ_Enqueue(PQ, Nodes[1]);
  PQ_Enqueue(PQ, Nodes[2]);
  PQ_Enqueue(PQ, Nodes[3]);
  PQ_Enqueue(PQ, Nodes[4]);
  PQ_Enqueue(PQ, Nodes[5]);

  printf("Number of remain works : %d\n", PQ->UsedSize);

  while(!PQ_IsEmpty(PQ)) {
    PQ_Dequeue(PQ, &Popped);
    PrintNode(&Popped);
  }
  return 0;
}