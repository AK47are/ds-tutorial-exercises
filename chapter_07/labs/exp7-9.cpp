#include <fstream>
#include <iostream>

#include "dependency.h"
const size_t MAX = 50;
using namespace std;
struct Record {
  SqString father;
  SqString wife;
  SqString son;
};
// 定义一个家谱记录的全局变量。
SqList<Record, MAX> fam;

void ReadFile() {
  ifstream fin("family_record.dat");
  Record temp;
  while (fin.good()) {
    fin >> temp.father >> temp.wife >> temp.son;
    fam.Insert(temp, fam.Size());
  }
  fam.Erase(fam.Size());
}

void Input() {
  Record temp;
  cout << "输入父亲，妻子和儿子：\n";
  cin >> temp.father >> temp.wife >> temp.son;
  fam.Insert(temp, fam.Size());
}

void Output() {
  for (int i = 0; i < fam.Size(); ++i) {
    cout << "父亲：" << fam[i].father << "\t妻子：" << fam[i].wife << "\t儿子："
         << fam[i].son << "\n";
  }
}

void DeleAll() { fam.Clear(); }

void SaveFile() {
  ofstream fout("family_record.dat");
  for (int i = 0; i < fam.Size(); ++i) {
    fout << fam[i].father << " " << fam[i].wife << " " << fam[i].son << "\n";
  }
}

void OperateFile() {
  for (char c = '\0'; c != '4'; cin >> c) {
    switch (c) {
      case '1':
        Input();
        break;
      case '2':
        Output();
        break;
      case '3':
        DeleAll();
        break;
    }
    cout << "文件操作界面：\n";
    cout << "1. 输入\t\t2. 输出\n"
         << "3. 清空\t\t4. 保存退出\n";
    cout << "选择：";
  }
  SaveFile();
}

BtNode<SqString>* CreateTree(SqString name) {
  BtNode<SqString>* root = new BtNode<SqString>(name);
  int i = 0;
  while (i < fam.Size() && fam[i].father != root->data) ++i;
  if (i < fam.Size()) {
    root->left = new BtNode<SqString>(fam[i].wife);
    BtNode<SqString>* temp = root;
    for (int j = i; j < fam.Size(); ++j) {
      if (fam[j].father == root->data) {
        temp->right = CreateTree(fam[j].son);
        temp = temp->right;
      }
    }
  }
  return root;
}

void DispTree(const BtNode<SqString>* root) {
  if (!root) return;
  cout << root->data;
  if (root->left || root->right) {
    cout << "(";
    DispTree(root->left);
    cout << ", ";
    DispTree(root->right);
    cout << ")";
  }
}

void FindAllSons() {
  SqString father;
  cout << "输入名字：";
  cin >> father;
  for (int i = 0; i < fam.Size(); ++i) {
    if (father == fam[i].father) cout << " " << fam[i].son;
  }
  cout << '\n';
}

void FindAllAncestors(LBTree<SqString>& family) {
  SqString name;
  cout << "输入名字：";
  cin >> name;
  LinkStack<BtNode<SqString>*> s;
  BtNode<SqString>* cur = family.GetRoot();
  BtNode<SqString>* prev;
  while (true) {
    while (cur) {
      s.Push(cur);
      cur = cur->left;
    }
    prev = nullptr;
    while (true) {
      cur = s.GetTop();
      // 代表顶点结点的左右子树都已访问。
      // NOTE: 一开始 prev = nullptr
      if (cur->right == prev) {
        if (name == cur->data) {
          for (auto i = s.Begin()->next; i != s.End(); i = i->next)
            cout << " " << i->data->data;
          cout << "\n";
        }
        s.Pop();
        if (s.Size() == 0) return;
        prev = cur;
        cur = s.GetTop();
      } else {
        cur = cur->right;
        break;
      }
    }
  }
}
void OperaoteFamily() {
  LBTree<SqString> family;
  if (fam.Size() != 0) family.GetRoot() = CreateTree(fam[0].father);
  for (char c = '\0'; c != '4'; cin >> c) {
    switch (c) {
      case '1':
        DispTree(family.GetRoot());
        cout << "\n";
        break;
      case '2':
        FindAllSons();
        break;
      case '3':
        FindAllAncestors(family);
        break;
      default:
        break;
    }
    cout << "家谱操作界面：\n";
    cout << "1. 输出家谱树\t\t2. 查找某人全部孩子\n"
         << "3. 查找某人全部祖先\t\t4. 退出\n";
    cout << "选择：";
  }
}

int main() {
  ReadFile();
  for (char c = '\0'; c != '3'; cin >> c) {
    switch (c) {
      case '1':
        OperateFile();
        break;
      case '2':
        OperaoteFamily();
        break;
    }
    cout << "主界面：\n";
    cout << "1. 文件操作\t\t2. 家谱操作\t\t3.退出\n";
    cout << "选择：";
  }
}
