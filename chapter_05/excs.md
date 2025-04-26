# 练习题5

### Q1:
有以下递归函数：
```cpp
void fun(int n) {
  if (n == 1)  {
    cout << "a: " << n << "\n";
  } else {
    cout << "b: " << n << "\n";
    fun(n - 1);
    cout << "c: " << n << "\n";
  }
}
```

#### 答案：
```sh
b: 5
b: 4
b: 3
b: 2
a: 1
c: 2
c: 3
c: 4
c: 5
```

---

### Q2:
有以下递归算法用于对数组 $a[i..j]$ 中的元素进行归并排序：
```cpp
void mergesort(int a[], int i, int j) {
  int m;
  if (i != j) {
    m = (i + j) / 2;
    mergesort(a, i, m);
    mergesort(a, m + 1, j);
    merge(a, i, j, m);
  }
}
```
求执行 $mergesort(a, 0, n - 1)$ 的时间复杂度。其中， $merge(a, i, j, m)$ 用于两个有序子序列 $a[i..m]$ 和 $a[m + 1..j]$ 的合并，是非递归函数，它的时间复杂度为 $O(合并的元素个数)$ 。

#### 答案：
$O(nlogn)$

---

### Q3:
已知 $A[0..n-1]$ 为实数数组，设计一个递归算法求这 $n$ 个元素的平均值。


#### 答案：
```cpp
double average(int A[], int n) {
  if (n <= 0) return 0;
  if (n == 1) return A[0];
  return (Average(A, n - 1) * (n - 1) + A[n - 1]) / n
}
```

---

### Q4:
设计一个算法求正整数 $n$ 的位数。

#### 答案：
```cpp
int digit(int n) {
  if (n == 0) return 0;
  return Digit(n / 10) + 1;
}
```

---

### Q5:
上楼可以一步上一个台阶，也可以一步上两阶，设计一个递归算法，计算共有多少种不同的走法。

#### 答案：
```cpp
int fun(int step_nums) {
  if (step_nums < 0) return 0;
  if (step_nums == 0) return 1;
  return fun(step - 2) + fun(step - 1);
}
```

---

### Q6:
设计一个递归算法，利用顺序串的基本运算求串 $s$ 的逆串。

#### 答案：
```cpp
void inverse(SqString& res, const SqString& target, int n) {
  if (n == 0) return;
  Inverse(res, target, n - 1);
  res.Push(target[n - 1]);
}
```

---

### Q7:
设有一个不带表头结点的单链表 $L$ ，设计一个递归算法 $count(L)$ 求以 $L$ 为首结点指针的单链表结点个数。

#### 答案：
```cpp
int count(const Node* L) const {
  if (L == nullptr) return 0;
  return count(L->next) + 1;
}
```

---

### Q8:
设有一个不带表头结点的单链表 $L$ ，设计两个递归算法， $traverse(L)$ 正向输出单链表 $L$ 中的所有结点值， $traverseR(L)$ 反向输出单链表 $L$ 中的所有结点值。


#### 答案：
```cpp
void traverse(const Node* L) {
  if (L == nullptr) return;
  cout << L->data;
  traverse(L->next);
}

void traverseR(const Node* L) {
  if (L == nullptr) return;
  traverse(L->next);
  cout << L->data;

}
```

---

### Q9:
设有一个不带表头结点的单链表 $L$ ，设计两个递归算法， $del(L, x)$ 删除单链表 $L$ 中第一个值为 $x$ 的结点， $delall(L, x)$ 删除单链表 L 中所有值为 $x$ 的结点。

#### 答案：
```cpp
void del(Node* L, const T& data) {
  if (L == nullptr) return;
  if (L->data == data) {
    delete L;
    return;
  }
  del(L->next, data);
}

void delall(Node* L, const T& data) {
  if (L == nullptr) return;
  delall(L->next, data);
  if (L->data == data) {
    delete L;
    return;
  }
}
```

---

### Q10:
设有一个不带表头结点的单链表 $L$ ，设计两个递归算法， $maxnode(L)$ 返回单链表 $L$ 中的最大结点值， $minnode(L)$ 返回单链表 $L$ 中的最小结点值。

#### 答案：
```cpp
T maxnode(const Node* L) {
  if (L == nullptr) return;
  if (L->next == nullptr) return L->data;
  T max = maxnode(L->next);
  return (L->data > max) ? L->data : max;
}

T minnode(const Node* L) {
  if (L == nullptr) return;
  if (L->next == nullptr) return L->data;
  T min = maxnode(L->next);
  return (L->data <= min) ? L->data : min;
}
```

---

### Q11:
设计一个模式匹配算法，其中模式串 $t$ 中含一个或多个通配符 `*` ，每个 `*` 可以和任意子串匹配。对于目标串 $t$ 的一个子串的位置（ `*` 不能出现在 $t$ 的开头 ）。

#### 答案：
```cpp
int find(const SqString& s, const SqString& t) {
  for (int i = 0; i < s.Size(); ++i) {
    for (int j = 0; j < t.Size(); ++j) {
      if (t[j] == '*') {
        int k = find(s.GetSubStr(i + j + 1, s.Size()), t.GetSubStr(j + 1, t.Size()));
        if (k != -1)
          return i - 1;
        else
          return -1;
      }
      if (s[i + j] != t[j]) break;
    }
      if (j == t.Size()) return i;
  }
  return -1;
}
```
