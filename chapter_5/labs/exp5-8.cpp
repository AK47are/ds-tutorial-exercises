#include <iostream>

#include "dependency.h"
using namespace std;

const unsigned MAX_ITEM = 6;

struct Item {
  unsigned code;
  unsigned value;
  unsigned weight;
  friend ostream& operator<<(ostream& os, const Item& coord) {
    os << "(" << coord.code << " : " << coord.value << ", " << coord.weight
       << ") + ";
    return os;
  }
};

bool IsAllow(const SqList<Item, MAX_ITEM>& stack, Item item) {
  if (item.code == 0) return false;
  for (int i = 0; i < stack.Size(); ++i) {
    if (stack[i].code == item.code) return false;
  }
  return true;
}

const unsigned MAX_WEIGHT = 15;
SqStack<Item, MAX_ITEM> sol;
unsigned max_value = 0, weight_sum = 0, value_sum = 0;

void Subtract(SqStack<Item, MAX_ITEM>& stack) {
  value_sum -= stack.GetTop().value;
  weight_sum -= stack.GetTop().weight;
  stack.Pop();
}

void Add(SqStack<Item, MAX_ITEM>& stack, const Item item) {
  value_sum += item.value;
  weight_sum += item.weight;
  stack.Push(item);
}

void MaxValue(SqStack<Item, MAX_ITEM>& stack, const Item item[], int count) {
  // cout << "第 " << count << " 个栈帧。\n";
  if (weight_sum > MAX_WEIGHT) {  // 不考虑全部都可以装下。
    Subtract(stack);
    if (max_value < value_sum) {
      sol = stack;
      max_value = value_sum;
    }
    // cout << "max_value: " << max_value << "\n";
    // cout << "返回第 " << count - 1 << " 个栈帧。\n";
    return;
  }
  int i = 0;
  while (true) {
    // cout << "i前：" << i << "\n";
    while (!IsAllow(stack, item[i]) && i < MAX_ITEM) ++i;
    // cout << i << "\n";
    if (i == MAX_ITEM) {
      Subtract(stack);
      // cout << "返回第 " << count - 1 << " 个栈帧。\n";
      // cout << "OK\n";
      return;
    } else {
      Add(stack, item[i]);
      // cout << stack << "\n";
      MaxValue(stack, item, count + 1);
    }
    ++i;
  }
}

int main() {
  Item item[MAX_ITEM] = {{1, 500, 10}, {2, 300, 7}, {3, 1000, 2},
                         {4, 150, 5},  {5, 200, 8}, {6, 900, 3}};
  SqStack<Item, MAX_ITEM> stack;
  int count = 1;  // 调试用。
  MaxValue(stack, item, count);
  cout << sol << "\n";
}
