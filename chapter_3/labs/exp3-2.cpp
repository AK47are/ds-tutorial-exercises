#include "../../docs/include/LinkStack.hpp"

using namespace std;
int main() {
  LinkStack<char> s;
  cout << s.IsEmpty() << "\n";
  char arr[6]{"abcde"};
  for (int i = 0; i < 5; ++i) {
    s.Push(arr[i]);
  }
  cout << s.Size() << "\n";
  cout << s.IsEmpty() << "\n";
  cout << s << "\n";
  cout << s.IsEmpty() << "\n";
}
