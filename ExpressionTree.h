#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;
typedef struct tagETNode {
  struct tagETNode* Left;
  struct tagETNode* Right;
  ElementType Data;
} ETNode;

ETNode* ET_CreateNode(ElementType NewData);
void ET_DestroyNode(ETNode* Node);
void ET_DestroyTree(ETNode* Root);
void ET_PreorderPrintNode(ETNode* Node);
void ET_InorderPrintNode(ETNode* Node);
void ET_PostorderPrintNode(ETNode* Node);
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node);
double ET_Evaluate(ETNode* Tree);

#endif