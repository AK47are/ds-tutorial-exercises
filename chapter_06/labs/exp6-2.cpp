#include <iostream>
#include <ostream>

#include "dependency.h"

class GLinkList;
using DataType = char;
enum class DTag { Atom, GLink };

struct GLinkNode {
  DTag tag;
  union {
    DataType val;
    GLinkList* l;  // 注意这个是指针。在复制时只能浅复制。
  };
  GLinkNode() = default;
  GLinkNode(char v) : tag(DTag::Atom), val(v) {}
  GLinkNode(GLinkList* link) : tag(DTag::GLink), l(link) {}
  GLinkNode(const GLinkNode&) = default;
};

class GLinkList : public LinkList<GLinkNode> {
  using List = LinkList<GLinkNode>;

 protected:
  int Depth(const GLinkList* g) const {
    int max_depth = 1;
    for (auto cur = g->Begin(); cur != g->End(); cur = cur->next) {
      if (cur->data.tag == DTag::GLink) max_depth = Depth(cur->data.l) + 1;
    }
    return max_depth;
  }

  std::ostream& Show(std::ostream& os) const {
    for (auto cur = Begin(); cur != End(); cur = cur->next) {
      if (cur->data.tag == DTag::Atom)
        os << cur->data.val;
      else
        cur->data.l->Show(os);
    }
    return os;
  }

 public:
  using List::LinkList;

  int Depth() const { return Depth(this); }

  friend std::ostream& operator<<(std::ostream& os, const GLinkList& s) {
    return s.Show(os);
  }
};

DataType Max(const GLinkList* g) {
  DataType max = 0;
  if (g->Size() == 0) return max;
  for (auto cur = g->Begin(); cur != g->End(); cur = cur->next) {
    if (cur->data.tag == DTag::Atom)
      max = (cur->data.val < max) ? max : cur->data.val;
    else
      max = (Max(cur->data.l) < max) ? max : Max(cur->data.l);
  }
  return max;
}

int main() {
  using namespace std;
  GLinkList g1, g2{'b', 'a', &g1, 'd'}, g3{'a', 'b'}, g4{&g1},
      g5{&g3, 'c', &g4};
  GLinkList g{'b', &g2, &g5};
  cout << "长度为：" << g.Size() << "\n"
       << "深度为：" << g.Depth() << "\n"
       << "最大原子为：" << Max(&g) << "\n";
}
