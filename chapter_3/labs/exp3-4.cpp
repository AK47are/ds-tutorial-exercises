#include "dependence.h"

using namespace std;
int main() {
  LinkQueue<char> s;
  cout << s.IsEmpty() << "\n";
  char arr[10]{"abcdef"};
  for (int i = 0; i < 3; ++i) {
    s.EnQueue(arr[i]);
  }
  cout << s.GetFront() << "\n";
  s.DeQueue();
  for (int i = 3; i < 6; ++i) {
    s.EnQueue(arr[i]);
  }
  cout << s << "\n";
  cout << "Size: " << s.Size() << "\n";
}
