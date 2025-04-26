#include <algorithm>
#include <iostream>

#include "dependency.h"
using namespace std;

struct Word {
  SqString word;
  unsigned frequency;
  friend ostream& operator<<(ostream& os, const Word& w) {
    os << " (" << w.word << ", " << w.frequency << ")";
    return os;
  }
};

BtNode<Word>* CreateHuffmanTree(BtNode<Word>* node[], int size) {
  BtNode<Word>* root;
  BtNode<Word>* temp;
  for (int i = 0; i < size - 1; ++i) {
    root = new BtNode<Word>(
        Word{"Null", node[i]->data.frequency + node[i + 1]->data.frequency});
    // cout << node[i]->data << " " << node[i + 1]->data << "\n";
    root->left = node[i];
    root->right = node[i + 1];
    node[i + 1] = root;
    for (int j = i + 1; j < size - 1; ++j) {
      if (node[j]->data.frequency < node[j + 1]->data.frequency) break;
      temp = node[j], node[j] = node[j + 1], node[j + 1] = temp;
    }
  }
  return root;
}

void DispCode(const BtNode<Word>* root, SqString& code) {
  if (!root) return;
  code.Push('0');
  DispCode(root->left, code);
  code.Pop();
  if (!root->left && !root->right) cout << root->data << ": " << code << "\n";
  code.Push('1');
  DispCode(root->right, code);
  code.Pop();
}

// NOTE:使用小顶堆更简单。
int main() {
  Word arr[15] = {{"The", 1192}, {"of", 677},  {"a", 541},    {"to", 518},
                  {"and", 462},  {"in", 450},  {"that", 242}, {"he", 195},
                  {"is", 190},   {"at", 181},  {"on", 174},   {"for", 157},
                  {"His", 138},  {"are", 124}, {"be", 123}};
  BtNode<Word>* node[15];
  for (int i = 0; i < 15; ++i) {
    node[i] = new BtNode<Word>(Word(arr[i]));
  }
  sort(node, node + 15, [](const BtNode<Word>* w1, const BtNode<Word>* w2) {
    return w1->data.frequency < w2->data.frequency;
  });
  LBTree<Word> t;
  t.GetRoot() = CreateHuffmanTree(node, 15);
  SqString temp;
  DispCode(t.GetRoot(), temp);
}
