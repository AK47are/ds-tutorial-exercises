#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Student {
  int number;
  string name;
  int age;
  string gender;
  int chinese;
  int math;
  int english;
};

void ReadFile(vector<Student>& st, ifstream& fin) {
  st.clear();
  Student s;
  while (fin >> s.number >> s.name >> s.age >> s.gender >> s.chinese >>
         s.math >> s.english) {
    st.push_back(s);
  }
  fin.close();
}

void Show(vector<Student>& st) {
  for (auto s : st) {
    cout << s.number << " " << s.name << " " << s.age << " " << s.gender << " "
         << s.chinese << " " << s.math << " " << s.english << "\n";
  }
}

int FindNum(vector<pair<int, int>>& key, int n) {
  auto res =
      lower_bound(key.begin(), key.end(), n,
                  [](const pair<int, int>& a, int n) { return a.first < n; });
  if (res->first != n)
    return -1;
  else
    return key[res - key.begin()].second - 1;
}

int main() {
  ifstream fin("data.dat");
  vector<Student> st;
  ReadFile(st, fin);
  Show(st);
  cout << "\n";
  vector<pair<int, int>> key(st.size());
  for (int i = 0; i < st.size(); ++i) {
    key[i].first = st[i].number;
    key[i].second = i + 1;
  }
  sort(key.begin(), key.end());
  for (auto i : key) {
    cout << i.first << " " << i.second << "\n";
  }
  const int n = 4;
  cout << "寻找学号为 " << n << " 的学生记录：\n";
  int index = FindNum(key, n);
  if (index != -1) {
    Student s = st[FindNum(key, n)];
    cout << s.number << " " << s.name << " " << s.age << " " << s.gender << " "
         << s.chinese << " " << s.math << " " << s.english << "\n";
  } else {
    cout << "没有找到！\n";
  }
}
