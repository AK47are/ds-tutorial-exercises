#include <fstream>
#include <iostream>

#include "dependency.h"
using namespace std;

struct Organ {
  SqString insti;
  SqString depart;
};

struct TNode {
  SqString data;
  TNode* arr[3]{nullptr};
};

TNode* Find(TNode* root, const SqString& data) {
  if (!root) return nullptr;
  // cout << root->data << "\n";
  if (root->data == data) return root;
  TNode* node = nullptr;
  for (int i = 0; i < 3; ++i) {
    node = Find(root->arr[i], data);
    if (node) return node;
  }
  return node;
}

void DispTree(const TNode* root) {
  if (!root) return;
  cout << root->data;
  if (root->arr[0]) {
    cout << "(";
    DispTree(root->arr[0]);
    cout << ", ";
    DispTree(root->arr[1]);
    cout << ", ";
    DispTree(root->arr[2]);
    cout << ")";
  }
}

int TransInt(const SqString& s) {
  int rtn = 0;
  for (int i = 0; i < s.Size(); ++i) {
    rtn *= 10;
    rtn += s[i] - '0';
  }
  // cout << "s: " << s << "\n";
  // cout << rtn << "\n";
  return rtn;
}

int Count(TNode* root) {
  if (!root) return 0;
  if (!root->arr[0] && !root->arr[1] && !root->arr[2])
    return TransInt(root->data);
  int sum = 0;
  for (int i = 0; i < 3; ++i) sum += Count(root->arr[i]);
  return sum;
}

void Delete(TNode*& root) {
  if (!root) return;
  for (int i = 0; i < 3; ++i) Delete(root->arr[i]);
  delete root;
  root = nullptr;
}
int main() {
  Organ arr[50];
  ifstream fin("abc.txt");
  int size = 0;
  while (size < 50 && fin.good()) {
    fin >> arr[size].insti >> arr[size].depart;
    ++size;
  }
  TNode* root = new TNode{arr[0].insti};
  for (int i = 0; i < size - 1; ++i) {
    // cout << arr[i].insti << " " << arr[i].depart << "OK\n";
    auto insti = Find(root, arr[i].insti);
    for (int j = 0; j < 3; ++j) {
      if (insti->arr[j] == nullptr) {
        insti->arr[j] = new TNode{arr[i].depart};
        break;
      }
    }
  }
  DispTree(root);
  cout << "\n";
  int major_count = 0;
  auto temp = Find(root, "计算机学院");
  while (major_count < 4 && temp->arr[major_count]) ++major_count;
  cout << "计算机学院有 " << major_count << " 个专业。\n";
  int class_count = 0;
  for (int i = 0; i < major_count; ++i) {
    auto cur = temp->arr[i];
    for (int j = 0; j < 3; ++j) {
      if (cur->arr[j]) ++class_count;
    }
  }
  cout << "计算机学院有 " << class_count << " 个班级。\n";
  cout << "电信学院有 " << Count(root->arr[1]) << " 人。\n";
  Delete(root);
}
