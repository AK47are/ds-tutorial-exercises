#include <string>

#include "sort.hpp"

struct Student {
  string name;
  string number;
  bool gender;
  bool status;

  void SetStatus(bool i) { status = i; }
  bool operator<=(const Student& s) const {
    if (status == 0)
      return number <= s.number;
    else
      return gender <= s.gender;
  }
  friend ostream& operator<<(ostream& os, const Student& s) {
    cout << s.number << " ";
    if (s.gender == 0)
      cout << "Male ";
    else
      cout << "Female ";
    cout << s.name << "\n";
    return os;
  }
};

int main() {
  vector<Student> students = {
      {"Alice", "1001", 0}, {"Bob", "1002", 1},    {"Charlie", "1001", 1},
      {"David", "1003", 1}, {"Eve", "1002", 0},    {"Frank", "1003", 0},
      {"Grace", "1001", 0}, {"Hannah", "1002", 0}, {"Ivy", "1003", 0},
      {"John", "1003", 1},  {"Kenny", "1001", 1},  {"Lily", "1002", 0},
      {"Mason", "1003", 1}, {"Nina", "1001", 0},   {"Oscar", "1002", 1},
      {"Paul", "1003", 1},  {"Quincy", "1001", 1}, {"Rebecca", "1002", 0},
      {"Sam", "1001", 1},   {"Tina", "1002", 0}};
  for (auto& s : students) s.status = 1;
  MergeSort(students);
  for (auto& s : students) s.status = 0;
  MergeSort(students);
  for (auto s : students) cout << s;
}
