#include "../../docs/include/SqQueue.hpp"

using namespace std;
int main() {
  SqQueue<char, 30> q;
  cout << q.IsEmpty() << "\n";
  char arr[6]{"abe"};
  for (int i = 0; i < 3; ++i) {
    q.EnQueue(arr[i]);
  }
  cout << q.GetFront() << "\n";
  q.DeQueue();
  cout << q << "\n";
}
