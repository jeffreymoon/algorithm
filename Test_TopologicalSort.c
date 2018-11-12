#include "Graph.h"
#include "TopologicalSort.h"

int main(void)
{
  Node* SortedList = NULL;
  Node* CurrentNode = NULL;
  Graph* G = CreateGraph();

  Vertex* VA = CreateVertex('A');
  Vertex* VB = CreateVertex('B');
  Vertex* VC = CreateVertex('C');
  Vertex* VD = CreateVertex('D');
  Vertex* VE = CreateVertex('E');
  Vertex* VF = CreateVertex('F');
  Vertex* VG = CreateVertex('G');
  Vertex* VH = CreateVertex('H');

  AddVertex(G, VA);
  AddVertex(G, VB);
  AddVertex(G, VC);
  AddVertex(G, VD);
  AddVertex(G, VE);
  AddVertex(G, VF);
  AddVertex(G, VG);
  AddVertex(G, VH);

  AddEdge(VA, CreateEdge(VA, VC, 0));
  AddEdge(VA, CreateEdge(VA, VD, 0));

  AddEdge(VB, CreateEdge(VB, VC, 0));
  AddEdge(VB, CreateEdge(VB, VE, 0));

  AddEdge(VC, CreateEdge(VC, VF, 0));

  AddEdge(VD, CreateEdge(VD, VF, 0));
  AddEdge(VD, CreateEdge(VD, VG, 0));

  AddEdge(VE, CreateEdge(VE, VG, 0));

  AddEdge(VF, CreateEdge(VF, VH, 0));

  AddEdge(VG, CreateEdge(VG, VH, 0));

  TopologicalSort(G->Vertices, &SortedList);

  printf("Topological Sort Result: ");
  CurrentNode = SortedList;

  while(CurrentNode != NULL) {
    printf("%c ", CurrentNode->Data->Data);
    CurrentNode = CurrentNode->NextNode;
  }
  printf("\n");
  DestroyGraph(G);
  return 0;
}