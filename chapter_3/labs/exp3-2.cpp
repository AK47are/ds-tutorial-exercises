#include "../../docs/include/LinkStack.hpp"

using namespace std;
int main() {
  LinkStack<char> s;
  cout << s.IsEmpty() << "\n";
  s.Push('a').Push('b').Push('c').Push('d').Push('e');
  cout << s.IsEmpty() << "\n";
  cout << s << "\n";
  cout << s.IsEmpty() << "\n";
}
