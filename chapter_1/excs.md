# 练习题1

### Q1：
简述数据与数据元素的关系与区别。

#### 答案：
>数据是描述客观事物的数和字符的集合。

数据元素是数据的基本单位。也就是说数据由数据元素构成，但数据元素一般具有明确的定义，更加具体。 

---

### Q2：
采用二元组表示的数据逻辑结构 S = `<D, R>`，其中 D = `{a, b, ..., i}`, R = `{r}`, r = `{<a, b>, <a, c>, <c, d>, <c, f>, <f, h>, <d, e>, <f, g>, <h, i>}`，问关系 r 是什么类型的逻辑结构？哪些结点是开始结点，哪些结点是终端结点？

#### 答案：
树形结构，a为开始节点，g和i为终端节点。 

---

### Q3：
简述数据逻辑结构与存储结构的关系。

#### 答案：
逻辑结构是对对应存储结构的抽象。存储结构是逻辑结构在现实生活中的体现。

---

### Q4：
简述数据结构中运算描述和运算实现的异同。

#### 答案：
运算描述只需说明运算的作用和效果，不必具体讲述实现的细节。

运算实现需要给出具体的实现细节。

两者都由实际的数据结构决定。

---

### Q5：
数据结构和数据类型有什么区别？

#### 答案：
数据类型是不同语言自带的数据结构。而数据结构则是在其之上进行的扩展，大部分情况下数据结构的实现并不依赖特定的语言数据类型。

---

### Q6：
在 C/C++ 中提供了引用运算符，简述其在算法描述中的主要作用。

#### 答案：
在算法描述中主要作用应该是表明该数据在算法中会发生改变。

---

### Q7：
有以下用 C/C++ 语言描述的算法，说明其功能：

```cpp
void fun(double &y, double x, int n) {
    y = x;
    while (n > 1) {
        y = y * x;
        n = n - 1;
    }
}
```

#### 答案：
$y = x^n$

---

### Q8：
用 C/C++ 语言描述下列算法，并给出算法的时间复杂度：

1. 求一个 n 阶二维数组的所有元素之和。
2. 对于输入的任意 3 个整数，将它们按从小到大的顺序输出。
3. 对于输入的任意 n 个整数，输出其中的最大和最小元素。

#### 答案：
1. $O(n^2)$
```cpp
// 算法复杂度O(n^2)
#include <cstdlib>
#include <ctime>
#include <iostream>
int main() {
  const int n = 10;
  int arr[n][n], sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << " " << (arr[i][j] = rand() % 100);
      sum += arr[i][j];
    }
    std::cout << "\n";
  }
  std::cout << "Sum: " << sum;
}
```

2. $O(n^2)$
```cpp
// 最坏时间复杂度 O(n^2)
#include <iostream>
int main() {
  const int MAX = 3;
  int arr[MAX];
  for (int i = 0; i < MAX; ++i) std::cin >> arr[i];
  for (int i = 0; i < MAX; ++i) {
    for (int j = i; j < MAX - i - 1; ++j) {
      int temp;
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < MAX; ++i) std::cout << " " << arr[i];
  std::cout << "\n";
}
```
   
3. $O(n)$
```cpp
// 最坏时间复杂度 O(n)
#include <iostream>
#include <ostream>
int main() {
  const int MAX = 3;
  int arr[MAX];
  for (int i = 0; i < MAX; ++i) std::cin >> arr[i];
  int max = arr[0], min = arr[0];
  for (int i = 0; i < MAX; ++i) {
    if (arr[i] < min) min = arr[i];
    if (arr[i] > max) max = arr[i];
  }
  std::cout << max << " " << min << std::endl;
}
```

---

### Q9：
设 f 表示函数的实际频度。f 和 h 分别为：

1. $f(n) = 100n^3 + n^2 + 1000$
2. $g(n) = 25n^3 + 5000n^2$
3. $h(n) = n^{1.5} + 5000n \log_{2}n$

求它们对应的时间复杂度。

#### 答案：
1. $O(n^3)$
2. $O(n^3)$
3. $O(n^{1.5})$

---

### Q10：
分析下面程序段中循环语句的执行次数。

```cpp
int j = 0, s = 0, n = 100;
do {
    j = j + 1;
    s = s + 10 * j;
} while (j < n && s < n);
```

#### 答案：
4

---

### Q11：
设 n 为正整数，给出下列 3 个算法关于问题规模 n 的时间复杂度。

#### 算法1：

```cpp
void fun1(int n) {
    int i = 1, k = 0;
    while (i <= n) {
        k = k + 1;
        i += 2;
    }
}
```

##### 答案：
$O(\sqrt n)$

#### 算法2：

```cpp
void fun2(int b[], int n) {
    int i, j, k, x;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (b[k] > b[j]) k = j;
        }
        x = b[i];
        b[i] = b[k];
        b[k] = x;
    }
}
```

##### 答案：
$O(n^2)$

#### 算法3：

```cpp
void fun3(int n) {
    int i = 0, s = 0;
    while (s <= n) {
        i++;
        s = s + i;
    }
}
```

##### 答案：
$O(\sqrt n)$

---

### Q12：
有以下归并算法用于对数组 a[l..j] 的元素进行归并排序：

```cpp
void mergesort(int a[], int l, int j) {
    int m;
    if (l != j) {
        m = (l + j) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, j);
        merge(a, l, j, m);
    }
}
```

求执行 `mergesort(a,0,n-1)` 的时间复杂度。  
其中 `merge(a, l, j, m)` 用于两个有序子序列 `a[l..m]` 和 `a[m+1..j]` 的合并，是非递归函数，时间复杂度为 O(合并的元素个数)。

##### 答案：
$O(n\log n)$

---
