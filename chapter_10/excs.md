# 练习题 10

### Q1:
直接插入排序算法在含有 $n$ 个元素的表的初始数据正序、反序和全部相等时的时间复杂度各是多少？

#### 答案：
$O(n), O(n^2), O(n)$

---

### Q2:
回答以下关于直接插入排序和折半插入排序的问题：
1. 使用折半插入排序所要进行的关键字比较次数是否和待排序的元素的初始状态有关？
2. 在一些特殊情况下，折半插入排序比直接插入排序要执行更多的关键字比较，这句话对吗？

#### 答案：
1. 否，因为最后都会变成有序的。
2. 对，例如初始数据已经正序。

---

### Q3:
有以下关于排序的算法：
```cpp
void fun(int a[], int n) {
    int d;
    d = n / 3;
    while (true) {
        for (int i = d; i < n; ++i) {
            int tmp = a[i];
            j = i - d;
            while (j >= 0 && tmp < a[j]) {
                a[j + d] = a[j];
                j -= d;
            }
            a[j + d] = tmp;
        }
        if (d == 1) 
            break;
        else if (d < 3)
            d = 1;
        else
            d = d / 3;
    }
}
```

1. 指出 $fun(a, n)$ 算法的功能。
2. 当 $a[] = {5, 1, 3, 6, 2, 7, 4, 8}$ 时，问 $fun(a, 8)$ 共执行几趟排序？各趟的排序结果是什么？

#### 答案：
1. 使用希尔排序，递减为 1 / 3。
2. 两趟。
```
第一趟排序：{2, 1, 3, 6, 4, 7, 5, 8}
第二趟排序：{1, 2, 3, 4, 5, 6, 7, 8}
```

---

### Q4:
在实现快速排序的非递归算法时，可根据基准元素将待排序序列划分为两个子序列。若下一趟首先对较短的子序列进行排序，试证明在此做法下快速排序所需的栈的深度为 $O(log_2{n})$ 。

#### 答案：
快排需要进行 log(n) 次排序，一般情况下判定树可能退化成链表，但如果只对较短的子序列进行递归，判定树高度最大只能为 log(n) 。

---

### Q5:
将快速排序算法改为非递归算法时通常使用一个栈，若把栈换为队列会对最终排序结果有什么影响？

#### 答案：
没有影响，快排先排左边还是右边都没有区别。

---

### Q6:
在堆排序、快速排序和二路归并排序中：
1. 若只从存储空间考虑，应首先选取哪种排序方法？其次选取哪种排序方法？最后选取哪种排序方法？
2. 若只从排序结果的稳定性考虑，则应选取哪种排序方法？
3. 若只从最坏情况下的排序时间考虑，则不应选取哪种排序方法？

#### 答案：
1. 堆排序、快速排序、二路归并排序。
2. 二路归并排序。
3. 快速排序。

---

### Q7:
如果只想在一个有 $n$ 个元素的任意序列中得到最小的前 $k(k << n)$ 个元素的部分排序序列，那么最好采用什么排序方法？为什么？例如有一个序列 (57, 40, 38, 11, 13, 34, 48, 75, 6, 19, 9, 7) ，要得到前 4 个最小元素 $(k = 4)$ 的有序序列，在用所选择的算法实现时要执行多少次比较？

#### 答案：
堆排序，所花时间大约为 $4n + klog_{2}{n}$ ，而冒泡和选择为 $kn$ 。33 次。

---

### Q8:
在基数排序过程中用队列暂存排序的元素，是否可以用栈来代替队列？为什么？

#### 答案：
不一定，如果只有单关键字没影响，多关键字可能会出错误。

---

### Q9:
线性表有顺序表和链表两种存储方式，不同的排序方法适合不同的存储结构。对于常见的内部排序方法，说明哪些更适合与顺序表？那些更适合与链表？哪些两者都适合？

#### 答案：
以 Chatgpt 回答为主。

适合顺序表的排序方法：桶排序、计数排序、基数排序、冒泡排序、选择排序、插入排序、快速排序、归并排序。

适合链表的排序方法：归并排序、插入排序。

---

### Q10:
设一个整数数组 $a[0 .. n - 1]$ 中存有互不相同的 $n$ 个整数，且每个元素的值均在 $1 \sim n$ 中。设计一个算法在 $O(n)$ 时间内将 $a$ 中的元素递增排序，将排序结果放在另一个同样大小的数组 $b$ 中。

#### 答案：
```cpp
void sort(int a[], int b[]) {
    for (int value : a) b[value - 1] = value;
}
```

---

### Q11:
设计一个双向冒泡排序算法，即在排序过程中交替改变扫描方向。

#### 答案：
```cpp
void Sort(int a[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        for (int i = low; i < high, ++i)
             if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        --high;
        for (int i = high; low < i, --i)
             if (a[i - 1] > a[i]) swap(a[i - 1], a[i]);
        ++low;
    }
}
```

---

### Q12:
假设有 $n$ 个关键字不同的元素存于顺序表中，要求不经过整体排序从中选出从大到小顺序的前 $m(m << n)$ 个元素。试采用简单选择排序实现此选择过程。

#### 答案：
```cpp
void sort(int a[], int n, int m) {
    int k = 0;
    while (k != m) {
        auto mmax = max_element(a + k, a + n);
        swap(*max,  a[k]);
        ++k;
    }
}
```

---

### Q13:
对于给定的含有 $n$ 个元素的无序数据序列（所有元素的关键字不相同），利用快速排序方法求这个序列中第 $k(1 \le k \le n)$ 小的元素的关键字，并分析设计算法的最好和平均时间复杂度。

#### 答案：
```cpp
// 最好时间复杂度 O(n) ， 平均复杂度 O(nlog(n))
void QuickSort(int a[], int size) {
    if (size <= 1) return;
    swap(a[0], a[size/ 2]);
    int low = 0, high = size - 1;
    while (low < high) {
        while (high > low && a[high] >= a[0]) --high;
        while (low < high && a[low] <= a[0]) ++low;
        swap(a[low], a[high]);
    }
    swap(a[0], a[low]);
    QuickSort(a,low);
    QuickSort(a +low + 1, size - low - 1);
}
```

---

### Q14:
设 $n$ 个元素 $R[0 .. n - 1]$ 的关键字只取 3 个值，即 0、1、2 ，采用基数排序方法将这 $n$ 个元素递增排序，并用相关数据进行测试。

#### 答案：
```cpp
// 只认为有一个关键字。
void sort(KeyType a[]) {
    queue<KeyType> q[3];
    for (auto data : a) {
        switch (data.key) {
            case 1:
                q[0].push(data);
                break;
            case 2:
                q[1].push(data);
                break;
            case 3:
                q[2].push(data);
                break;
        }
    }
    int top = 0;
    for (int i = 0; i < 3; ++i) {
        while (!q[2 - i].empty()) {
            a[top++] = q[2 - i].front();
            q[2 - i].pop();
        }
    }
}
```