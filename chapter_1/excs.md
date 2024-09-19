# 练习题1

### Q1：
简述数据与数据元素的关系与区别。

#### 答案：
>数据是描述客观事物的数和字符的集合。

数据元素是数据的基本单位。也就是说数据由数据元素构成。

---

### Q2：
采用二元组表示的数据逻辑结构 S = `<D, R>`，其中 D = `{a, b, ..., i}`, R = `{r}`, r = `{<a, b>, <a, c>, <c, d>, <c, f>, <f, h>, <d, e>, <f, g>, <h, i>}`，问关系 r 是什么类型的逻辑结构？哪些结点是开始结点，哪些结点是终端结点？

#### 答案：
树形结构，a为开始节点，b，e，i和g为终端节点。 

---

### Q3：
简述数据逻辑结构与存储结构的关系。

#### 答案：
逻辑结构是对对应存储结构的抽象。存储结构是逻辑结构在现实中的体现。存储结构不仅将逻辑结构中的所有数据元素存储到计算机内存中，而且还会存储其逻辑关系。一般情况下一种逻辑结构可以有多种存储结构。

---

### Q4：
简述数据结构中运算描述和运算实现的异同。

#### 答案：
运算描述只需说明运算的作用和效果，不必具体讲述实现的细节。而运算实现需要给出具体的实现细节。

两者都能完成指定操作，只是描述重点不同。

---

### Q5：
数据结构和数据类型有什么区别？

#### 答案：
数据结构需要包含各元素之间的逻辑关系。

---

### Q6：
在 C/C++ 中提供了引用运算符，简述其在算法描述中的主要作用。

#### 答案：
实现了形参和实参的双向值传递。在算法描述中主要作用应该是表明该数据在算法中会发生改变。

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

2. $O(1)$
```cpp
// 时间复杂度 O(1) 因为 MAX 已确定。
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
$O(n)$

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

### Q13:
描述一个集合的抽象数据类型 $ASet$ ，其中所有元素为正整数且所有元素不相同，集合的基本运算包括：
1. 有整数数组 $a[0..n-1]$ 创建一个集合。
2. 输出一个集合中的所有元素。
3. 判断一个元素是否在一个集合中。
4. 求两个集合的并集。
5. 求两个集合的差集。
6. 求两个集合的交集。

在此基础上设计集合的顺序存储结构，并实现个基本运算的算法。

#### 答案：
**ADT ASet**
- **数据对象：**
  - $D = \{e_i | e_i > 0 且 e_i \neq e_j (i \neq j; i, j = 1, 2, ...) \}$
- **数据关系：**
  - $R = 无
- **基本运算：**
  - `CreateSet(&Z, a[], n)`：用 $a[0..n-1]$ 创建一个集合 $Z$。（&代表引用，后面不再赘述）
  - `PrintAll(Z)`：输出集合 $Z$ 中的全部元素。
  - `isHas(Z, x)`：判断 $x$ 是否在集合 $Z$ 中。
  - `UnionSet(&Z, Z1, Z2)`：将 $Z1$ 和 $Z2$ 的并集返回给集合 $Z$。
  - `DifferSet(&Z, Z1, Z2)`：将 $Z1$ 和 $Z2$ 的差集返回给集合 $Z$。
  - `IntersSet(&Z, Z1, Z2)`：将 $Z1$ 和 $Z2$ 的交集返回给集合 $Z$。

**顺序存储结构：**
```cpp
struct Set {
  int a[MAX];
  int length;
};
```

**基本运算：**
1. 初始化：
    ```cpp
    void CtreateSet(Set& Z, int a[], int n) { // 不考虑 n 太大的情况。
      for (int i = 0; i < n; ++i) Z.a[i] = a[i];
      Z.length = n;
    }
    ```

2. 全部打印：
    ```cpp
    void PrintAll(Set Z) { // 可以优化参数，这是按课本标准答案搞得。
      for (int i = 0; i < Z.length; ++i) cout << Z.a[i] << "\n";
    }
    ```

3. 是否存在 $x$ ：
    ```cpp
    bool isHas(Set Z, int x) {
      for (int i = 0; i < Z.length; ++i) 
        if (Z.a[i] == x) return 1;
      return 0;
    }
    ```
     
4. 两个集合并集：
    ```cpp
    void UnionSet(Set& Z, Set Z1, Set Z2) {
      for (int i = 0; i < Z1.length; ++i) Z.a[i] = Z1.a[i];
      Z.length = Z1.length;
      for (int i = Z1.length; i < Z1.length + Z2.length; ++i)
        if (!isHas(Z, Z2.a[i])) {
          Z.a[Z.length] = Z2.a[i];
          ++Z.length;
        }
    }
    ```

5. 两个集合差集：
    ```cpp
    void DifferSet(Set& Z, Set Z1, Set Z2) {
      Z.length = 0;
      for (int i = 0; i < Z1.length; ++i)
        if (!isHas(Z2, Z1.a[i])) {
          Z.a[Z.length] = Z1.a[i];
          ++Z.length;
        }
    ```

6. 两个集合交集：
    ```cpp
    void IntersSet(Set& Z, Set Z1, Set Z2) {
      Z.length = 0;
      for (int i = 0; i < Z1.length; ++i)
        if (isHas(Z2, Z1.a[i])) {
          Z.a[Z.length] = Z1.a[i];
          ++Z.length;
        }
    }
    ```

---
