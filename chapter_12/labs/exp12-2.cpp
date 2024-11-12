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

void WriteFile(vector<Student>& st, ofstream& fout) {
  for (auto s : st) {
    fout << s.number << " " << s.name << " " << s.age << " " << s.gender << " "
         << s.chinese << " " << s.math << " " << s.english << "\n";
  }
  fout.close();
}

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

int main() {
  vector<Student> st{
      {1, "陈华", 20, "男", 78, 90, 84}, {5, "张明", 21, "男", 78, 68, 92},
      {8, "王英", 20, "女", 86, 81, 86}, {3, "刘丽", 21, "女", 78, 92, 88},
      {2, "许可", 20, "男", 80, 83, 78}, {4, "陈军", 20, "男", 78, 88, 82},
      {7, "马胜", 21, "男", 56, 67, 75}, {6, "曾强", 20, "男", 78, 89, 82},
  };
  ofstream fout("stud.dat");
  WriteFile(st, fout);
  ifstream fin("stud.dat");
  ReadFile(st, fin);
  Show(st);
  cout << "\n";
  vector<pair<Student, int>> average(st.size());
  for (int i = 0; i < st.size(); ++i) {
    average[i].first = st[i];
    average[i].second = double(st[i].chinese + st[i].math + st[i].english) / 3;
  }
  sort(average.begin(), average.end(),
       [](const pair<Student, int>& p1, const pair<Student, int> p2) {
         return p1.second > p2.second;
       });
  vector<Student> st1(st.size());
  for (int i = 0; i < st1.size(); ++i) {
    st1[i] = average[i].first;
  }
  fout.open("stud1.dat");
  WriteFile(st1, fout);
  fin.open("stud1.dat");
  ReadFile(st1, fin);
  Show(st1);
}
