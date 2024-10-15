#include "../../docs/include/SqQueue.hpp"

using namespace std;
int main() {
  SqQueue<char, 30> q;
  cout << q.IsEmpty() << "\n";
  q.EnQueue('a').EnQueue('b').EnQueue('c');
  cout << q.GetFront() << "\n";
  q.DeQueue();
  cout << q << "\n";
}
