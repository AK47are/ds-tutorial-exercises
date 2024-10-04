# 练习题3

### Q1:
有 5 个元素，其进栈次序为 ABCDEF，在各种可能的出栈次序中以 C, D ，最先出栈（即 C 第一个且 D 第二个出栈）的次序有哪几个？？

#### 答案：
3 个

---

### Q2:
在一个算法中需要建立多个栈（假设 3 个栈或以上）时可以选用以下 3 中方案之一，试问这些方案各有什么优缺点？
1. 分别用多个顺序存储空间建立多个独立的顺序栈。
2. 多个战功像一个顺序存储空间。
3. 分别建立多个独立的链栈。

#### 答案：
1. 存储密度大，但比较浪费内存空间。并且容载量有限。
2. 降低了内存空间的浪费，其他同上。
3. 容载量无限，不额外浪费内存空间，存储密度小。

---

### Q3:
在以下几种存储结构中那种最适合用作链栈？
1. 带头结点的单链表。
2. 不带头结点的循环单链表。
3. 带头结点的双链表。

#### 答案：
带头结点的单链表。

---

### Q4:
简述以下算法的功能（假设 ElemType 为 int 类型）。
```cpp
void fun(ElemType a[], int n) {
  SqStack* st1;
  SqStack* st2;
  InitStack(st1), InitStack(st2);
  for (int i = 0; i < n; ++i)
    if (a[i] % 2 == 1)
      Push(st1, a[i]);
    else
      Push(st2, a[i]);
  ElemType e;
  for (int i = 0; !StackEmpty(st1); ++i) {
    Pop(st1, e);
    a[i] = e;
  }
  for (int i = 0; !StackEmpty(st2); ++i) {
    Pop(st2, e);
    a[i] = e;
  }
  DestroyStack(st1), DesTroyStack(st2);
}
```

#### 答案：
将 $a$ 数组中的奇数排在偶数前面。

---

### Q5:
简述以下算法的功能（顺序栈的元素类型为 ElemType）。
```cpp
void fun(SqStack*& st, ElemType x) {
  SqStack* tmps;
  InitStack(tmps);
  ElemType e;
  while (!StackEmpty(st)) {
    Pop(st, e);
    if (e != x) Push(tmps, e);
  } 
  while (!StackEmpty(tmps)) {
    Pop(tmps, e);
    Push(st, e);
  }
  DestroyStack(tmps);
}
```

#### 答案：
删除栈中值为 x 的元素。

---

### Q6:
简述以下算法的功能（队列 qu 的元素类型为 ElemType）。
```cpp
bool fun(SqQueue*& qu, int i) {
  ElemType e;
  int n = (qu->rear - qu->front + MaxSize) % MaxSize;
  if (i < 1 || i > n) return false;
  for (int j = 1; i <= n; ++j) {
    deQueue(qu, e);
    if (j != i) enQueue(qu, e);
  }
  return true;
}
```

#### 答案：
删除队列中第 i 个元素。

---

### Q7:
什么是环形队列？采用什么方法实现环形队列？

#### 答案：
环形队列指将队列首尾相连，为了充分利用空间。

使用模运算。当 rear 指针指向末尾时, 如果顶端有无用空间, 那么将元素添加到顶端。通
过模运算得到该指向顶端哪个空间。

---

### Q8:
环形队列一定优于非环形队列吗？在什么情况下使用非环形队列？

#### 答案：
环形队列用来解决假溢出的情况。当可能使用回溯算法时最好使用非环形队列，因为环形队
列会覆盖回溯值。

---

### Q9:
假设以 $I$ 和 $O$ 分别表示进栈和出栈操作，栈的初态和终态均为空，进栈和出栈的操作
序列可表示为仅由 $I$ 和 $O$ 组成的序列。
1. 在下面的序列中哪些是合法的？<br>
    A. $IOIIOIOO$ <br>
    B. $IOOIOIIO$ <br>
    C. $IIIOIOIO$ <br>
    D. $IIIOOIOO$ <br>

2. 通过对 (1) 的分析，设计一个算法判断所给的操作序列是否合法，若合法返回真，否则
   返回假（假设被判断的操作序列已存入一维数组中）。

#### 答案：
1. AD
2. 法一：
    ```cpp
    bool IsAllow(char a[], int n) {
      int I_nums = 0, O_nums = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == 'I') ++I_nums;
        if (a[i] == 'O') ++O_nums;
        if (I_nums < O_nums) return false;
      }
      if (I_nums == O_nums) return true;
      return false;
    }
    ```
   法二：
    ```cpp
    bool IsAllow(char a[], int n) {
      LinkStack<char> s;
      for (inti = 0; i < n; ++i) {
        if (a[i] == 'I') s.Push('I');
        if (a[i] == 'O')
          if (s.IsEmpty())
            return false;
          else
            s.Pop();
      }
      if (s.IsEmpty())
        return true;
      else
        return false;
    }
    ```

---

### Q10:
假设表达式中允许包含圆括号、方括号和大括号 3 种括号（有优先级），编写一个算法判断表达式中的括号是否正确配对。

#### 答案：
```cpp
bool IsMatch(char a[], int n) {
  LinkStack<char> s;
  for (int i = 0; i < n; ++i) {
    switch (a[i]) {
      case '(':
      case '[':
      case '{':
        s.Push(a[i]);
        break;

      case ')':
        if (s.GetTop() != '(') return false;
        break;
      case ']':
        if (s.GetTop() != '[') return false;
        break;
      case '}':
        if (s.GetTop() != '{') return false;
        break;

      default:
        break;
    }
    s.Pop();
  }
  if (s.IsEmpty())
    return true;
  else
    return false;

}
```

---

### Q11:
设从键盘输入一个序列的字符 $a_1, a_2, ... , a_n$ 。设计一个算法实现这样的功能
：若 $a_i$ 为数字字符， $a_i$ 进队；若 $a_i$ 为小写字母，将队首元素出队；若$
a_i$ 为其他字符，表示输入结束。要求使用环形队列。

#### 答案：
```cpp
int main() {
  Queue q;
  for (char c = '\0'; isalnum(c); cin >> c) {
    if (isdigit(c)) q.EnQueue(c);
    if (isalpha(c)) q.DeQueue();
  }
}
```

---

### Q12:
设计一个算法，将一个环形队列（容量为 $n$ ， 元素的下标从 0 到 $n - 1$ ）中的元素
倒置（元素之间的顺序反转）。

#### 答案：
```cpp
void Reverse(Queue& q) {
  Stack s;
  while (!q.IsEmpty()) s.Push(q.DeQueue());
  while (!s.IsEmpty()) q.EnQueue(s.Pop());
}
```

---

### Q13:
编写一个程序，输入 $n$ （由用户输入）个 10 以内的数，每输入 $i (0 \le i \ge 9)$ 
就把它插入到第 $i$ 号队列中，最后把 10 个队中的非空队列按队列号从小到大的顺序
串接成一条链，并输出该链中的所有元素。

#### 答案：
```cpp
int main() {
  int n;
  cout << "你要输入几个数：";
  cin >> n;
  int temp;
  Queue a[10];
  for (int i = 0; i < n; ++i) {
    cout << "输入第 " << i + 1 << " 个数字：";
    cin >> temp;
    a[temp].EnQueue(temp);
  }
  Queue b;
  for (int i = 0; i < n; ++i)
    if (!a[i].IsEmpty()) merge(b, a[i]);
  cout << b << "\n";
}
```

---
