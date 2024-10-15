#include <iostream>
#include <string>

#include "../../docs/include/LinkQueue.hpp"
using namespace std;

class Nurse;
class Patient {
 private:
  string medical_record_number;

 public:
  Patient() = default;
  void LineUp(Nurse& nurse);
  friend istream& operator>>(istream& is, Patient& patient) {
    cout << "输入病历号：";
    is >> patient.medical_record_number;
    return is;
  }
};

class Nurse {
  LinkQueue<string> waiting_queue_;

 public:
  friend Patient;
  Nurse() = default;
  void Examination() { waiting_queue_.DeQueue(); };
  friend ostream& operator<<(ostream& os, Nurse& nurse) {
    os << nurse.waiting_queue_;
    return os;
  }
};

int main() {
  Nurse nurse;
  Patient patient;
  for (char c = '\0'; c != 'q'; cin >> c) {
    switch (c) {
      case '1':
        cin >> patient;
        patient.LineUp(nurse);
        break;
      case '2':
        nurse.Examination();
        break;
      case '3':
        cout << nurse << "\n";
        break;
      case '4':
        cout << nurse << "\n";
        return 1;
      case '5':
        return 1;
      default:
        break;
    }
    cout << "1. 排队\t\t2. 就诊\t\t3.查看排队\n4. 不在排队，余下依次就诊\n"
            "5. 下班\n"
         << "进行你的选择：";
  }
}

void Patient::LineUp(Nurse& nurse) {
  nurse.waiting_queue_.EnQueue(medical_record_number);
}
