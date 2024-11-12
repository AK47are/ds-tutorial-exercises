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

void WriteFile(vector<Student>& st) {
  ofstream fout("stud.dat");
  for (auto s : st) {
    fout << s.number << " " << s.name << " " << s.age << " " << s.gender << " "
         << s.chinese << " " << s.math << " " << s.english << "\n";
  }
  fout.close();
}

void FindI(int i) {
  ifstream fin("stud.dat");
  while (--i) fin.ignore(1000, '\n');
  string line;
  getline(fin, line);
  cout << line << "\n";
  fin.close();
}

void FindNum(int num) {
  ifstream fin("stud.dat");
  int tmp;
  while (fin >> tmp) {
    if (tmp == num) {
      string line;
      getline(fin, line);
      cout << num << " " << line << "\n";
      break;
    } else {
      fin.ignore(1000, '\n');
    }
  }
  fin.close();
}

int main() {
  vector<Student> st{
      {1, "陈华", 20, "男", 78, 90, 84}, {5, "张明", 21, "男", 78, 68, 92},
      {8, "王英", 20, "女", 86, 81, 86}, {3, "刘丽", 21, "女", 78, 92, 88},
      {2, "许可", 20, "男", 80, 83, 78}, {4, "陈军", 20, "男", 78, 88, 82},
      {7, "马胜", 21, "男", 56, 67, 75}, {6, "曾强", 20, "男", 78, 89, 82},
  };
  WriteFile(st);
  FindI(5);
  FindNum(7);
}
