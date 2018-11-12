#include "ExpressionTree.h"

int main(void)
{
  ETNode* Root = NULL;
  char PostfixExpression[20] = "71*52-/";
  ET_BuildExpressionTree(PostfixExpression, &Root);

  printf("Preorder ...\n");
  ET_PreorderPrintNode(Root);
  printf("\n\n");

  printf("Inorder ...\n");
  ET_InorderPrintNode(Root);
  printf("\n\n");

  printf("Postorder ...\n");
  ET_PostorderPrintNode(Root);
  printf("\n\n");

  printf("Evaulation Result : %f \n", ET_Evaluate(Root));

  ET_DestroyTree(Root);

  return 0;
}