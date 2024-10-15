#include <iostream>

#include "../../docs/include/LinkStack.hpp"
using namespace std;

int main() {
  LinkStack<char> stack{'1', '3', '5', '2', '4'};
  LinkStack<char> temp;
  cout << stack << "\t\t" << temp << "\n";
  temp.Push(stack.GetTop());
  stack.Pop();
  char c;
  while (true) {
    while (!stack.IsEmpty() && temp.GetTop() < stack.GetTop()) {
      cout << stack << "\t\t" << temp << "\n";
      temp.Push(stack.GetTop());
      stack.Pop();
    }
    cout << stack << "\t\t" << temp << "\n";
    if (stack.IsEmpty()) break;
    c = stack.GetTop();
    stack.Pop();
    while (!temp.IsEmpty() && temp.GetTop() > c) {
      cout << stack << "\t\t" << temp << "\t\t" << "c = " << c << "\n";
      stack.Push(temp.GetTop());
      temp.Pop();
    }
    temp.Push(c);
  }
  while (!temp.IsEmpty()) {
    stack.Push(temp.GetTop());
    temp.Pop();
  }
  cout << stack << "\t\t" << temp << "\n";
}
