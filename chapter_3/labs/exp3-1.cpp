#include "../../docs/lib/include/SqStack.h"

using namespace std;
int main() {
  SqStack<char, 30> s;
  cout << s.IsEmpty() << "\n";
  s.Push('a').Push('b').Push('c').Push('d').Push('e');
  cout << s.IsEmpty() << "\n";
  cout << s << "\n";
  cout << s.IsEmpty() << "\n";
}
