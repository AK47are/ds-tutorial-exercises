// NOTE: 四则运算中对于括号要特殊处理，处理巧妙，有分治那味了。
// TODO: 支持多位数四则表达式运算。
#include <iostream>
#include <string>

#include "../../docs/lib/include/LinkStack.h"

using namespace std;
void Dispose(string&);
string Transform(const string& expresion);
double Calculate(const string& expresion);

int main() {
  string expresion;
  expresion.resize(50);  // NOTE:不加这个就会出 bug 。
  cout << "输入表达式（支持 +, -, *, / 和括号）：";
  getline(cin, expresion);
  Dispose(expresion);
  cout << "处理后：" << expresion << "\n";
  expresion = Transform(expresion);
  cout << "转化为后缀表达式：" << expresion << "\n";
  cout << "计算得值：" << Calculate(expresion) << "\n";
}

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

void Dispose(string& expr) {
  for (auto cur = expr.begin(); cur != expr.end(); ++cur)
    if (!isdigit(*cur) && !Priority(*cur)) expr.erase(cur), --cur;
}

string Transform(const string& expr) {
  string res;
  LinkStack<char> temp;
  for (auto cur = expr.begin(); cur != expr.end(); ++cur) {
    // cout << res << endl;
    switch (Priority(*cur)) {
      case LOWEST: {
        res.push_back(*cur);
        break;
      }

      case LOW:
      case MEDIUM:
      case HIGH: {
        while (!temp.IsEmpty() && temp.GetTop() != '(' &&
               Priority(*cur) <= Priority(temp.GetTop())) {
          res.push_back(temp.GetTop());
          temp.Pop();
        }
        temp.Push(*cur);
        break;
      }

      case HIGHEST: {
        if (*cur == '(') temp.Push(*cur);
        if (*cur == ')') {
          while (!temp.IsEmpty() && temp.GetTop() != '(') {
            res.push_back(temp.GetTop());
            temp.Pop();
          }
          temp.Pop();
        }
        break;
      }
      default:
        break;
    }
  }
  while (!temp.IsEmpty()) {
    res.push_back(temp.GetTop());
    temp.Pop();
  }
  return res;
}

double Calculate(const string& expr) {
  LinkStack<double> temp;
  double temp1, temp2;
  for (auto cur = expr.begin(); cur != expr.end(); ++cur) {
    if (isdigit(*cur))
      temp.Push(*cur - '0');
    else {
      temp1 = temp.GetTop(), temp.Pop();
      temp2 = temp.GetTop(), temp.Pop();
      switch (*cur) {
        case '+':
          temp.Push(temp2 + temp1);
          break;
        case '-':
          temp.Push(temp2 - temp1);
          break;
        case '*':
          temp.Push(temp2 * temp1);
          break;
        case '/':
          temp.Push(temp2 / temp1);
        default:
          break;
      }
    }
  }
  return temp.GetTop();
}
