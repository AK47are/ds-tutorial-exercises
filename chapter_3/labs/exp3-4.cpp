#include "../../docs/include/LinkQueue.hpp"

using namespace std;
int main() {
  LinkQueue<char> s;
  cout << s.IsEmpty() << "\n";
  s.EnQueue('a').EnQueue('b').EnQueue('c');
  cout << s.GetFront() << "\n";
  s.DeQueue();
  s.EnQueue('d').EnQueue('e').EnQueue('f');
  cout << s << "\n";
  cout << "Size: " << s.Size() << "\n";
}
