#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
  LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
  NewNode->LeftChild = NULL;
  NewNode->RightSibling = NULL;
  NewNode->Data = NewData;
  return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
  free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
  if (Root->RightSibling != NULL) {
    free(Root->RightSibling);
  }
  if (Root->LeftChild != NULL) {
    LCRS_DestroyTree(Root->LeftChild);
  }

  Root->RightSibling = NULL;
  Root->LeftChild = NULL;

  LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode)
{
  if (ParentNode->LeftChild == NULL) {
    ParentNode->LeftChild = ChildNode;
  } else {
    LCRSNode* TempNode = ParentNode->LeftChild;
    while(TempNode->RightSibling != NULL) {
      TempNode = TempNode->RightSibling;
    }
    TempNode->RightSibling = ChildNode;
  }
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
  int i = 0;
  for (i = 0; i < Depth; ++i) {
    printf(" ");
  }
  printf("%c\n", Node->Data);

  if (Node->LeftChild != NULL) {
    LCRS_PrintTree(Node->LeftChild, Depth+1);
  }
  if (Node->RightSibling != NULL) {
    LCRS_PrintTree(Node->RightSibling, Depth);
  }
}