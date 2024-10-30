#include "dependency.h"
using namespace std;

enum { LOWEST, LOW, MEDIUM, HIGH, HIGHEST };
int Priority(char c) {
  switch (c) {
    default:
      return LOWEST;
    case '-':
    case '+':
      return MEDIUM;
    case '*':
    case '/':
      return HIGH;
    case '(':
    case ')':
      return HIGHEST;
  }
}

BtNode<int>* CreateExpressionTree(const char in_order[], const int& size) {
  if (size % 2 == 0) return nullptr;
  if (size == 1) return new BtNode<int>(in_order[0] - '0');
  int min_priority = 1;
  for (int i = 3; i < size; i += 2) {
    if (Priority(in_order[i]) <= Priority(in_order[min_priority]))
      min_priority = i;
  }
  BtNode<int>* root = new BtNode<int>(in_order[min_priority]);
  root->left = CreateExpressionTree(in_order, min_priority);
  root->right = CreateExpressionTree(in_order + min_priority + 1,
                                     size - min_priority - 1);
  return root;
}

double Calculate(char c, double n1, double n2) {
  switch (c) {
    case '+':
      return n1 + n2;
    case '-':
      return n1 - n2;
    case '*':
      return n1 * n2;
    case '/':
      return n1 / n2;
  }
  return 0;
}

double CalculateExpression(BtNode<int>* root) {
  if (!root->left && !root->right) return root->data;
  double num1 = CalculateExpression(root->left);
  double num2 = CalculateExpression(root->right);
  return Calculate(root->data, num1, num2);
}

int main() {
  const char* in_order = "1+2*3-4/5";
  LBTree<int> t;
  t.GetRoot() = CreateExpressionTree(in_order, 9);
  cout << CalculateExpression(t.GetRoot()) << "\n";
}
