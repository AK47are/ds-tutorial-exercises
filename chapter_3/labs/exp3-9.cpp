#include <cstdlib>
#include <iostream>
#include <ostream>

#include "dependence.h"

class ParkingLot;
struct Car {
  size_t license;
  size_t parking_time = 0;
  bool IsQuit() const {
    if (rand() % 20 < 1)
      return true;
    else
      return false;
  }
  bool Waiting(ParkingLot& pl);
  bool Parking(ParkingLot& pl);
  size_t GiveFee() const { return 5 * parking_time; };
  void Reset() { parking_time = 0; }
  Car& operator=(const Car&) = default;
  friend std::ostream& operator<<(std::ostream& os, const Car& car) {
    std::cout << "(" << car.license << ", " << car.parking_time << ")";
    return os;
  }
};

class ParkingLot {
 private:
  size_t income = 0;
  SqStack<Car, 10> parking_area;
  LinkQueue<Car> waiting_area;

 public:
  friend struct Car;
  size_t GetIncome() { return income; }
  void UpdatePark() {
    if (!parking_area.IsFull() && !waiting_area.IsEmpty()) {
      std::cout << "候车区车辆 " << waiting_area.GetFront().license
                << " 将要停车\n";
      parking_area.Push(waiting_area.GetFront());
      waiting_area.DeQueue();
    }
  }
  void UpdateTime() {
    SqStack<Car, 10> temp;
    while (!parking_area.IsEmpty()) {
      Car tem = parking_area.GetTop();
      ++tem.parking_time;
      temp.Push(tem);
      parking_area.Pop();
    }
    while (!temp.IsEmpty()) {
      parking_area.Push(temp.GetTop());
      temp.Pop();
    }
  }
  void AskQuit() {
    SqStack<Car, 10> temp;
    while (!parking_area.IsEmpty() && !parking_area.GetTop().IsQuit()) {
      temp.Push(parking_area.GetTop());
      parking_area.Pop();
    }
    if (!parking_area.IsEmpty()) {
      std::cout << "车辆 " << parking_area.GetTop().license << " 将要离开\n";
      income += parking_area.GetTop().GiveFee();
      parking_area.Pop();
    }
    while (!temp.IsEmpty()) {
      parking_area.Push(temp.GetTop());
      temp.Pop();
    }
    UpdatePark();
  }
  friend std::ostream& operator<<(std::ostream& os, ParkingLot& lot) {
    std::cout << "停车区情况：\n"
              << lot.parking_area << "\n"
              << "候车区情况：\n"
              << lot.waiting_area << "\n";
    std::cout << lot.waiting_area.Size() << "\n";
    return os;
  }
};

bool Car::Waiting(ParkingLot& pl) {
  pl.waiting_area.EnQueue(*this);
  return true;
}
bool Car::Parking(ParkingLot& pl) {
  if (pl.parking_area.IsFull()) return false;
  pl.parking_area.Push(*this);
  return true;
}

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));
  const size_t TestTime = 100;
  size_t arrive_car_number = 0;
  ParkingLot AK;
  for (int i = 0; i < TestTime; ++i) {
    std::cout << "第 " << i << " 小时后 AK 停车场情况：\n" << AK;
    AK.UpdateTime();
    AK.AskQuit();
    if (rand() % 4 < 3) {
      std::cout << "第 " << arrive_car_number + 1 << " 号车辆到达\n";
      Car car{arrive_car_number++};
      if (!car.Parking(AK)) {
        std::cout << "停车位置已满！\n";
        car.Waiting(AK);
      }
    }
  }
  std::cout << "总收入：" << AK.GetIncome() << "\n";
}
