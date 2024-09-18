# 练习题2

### Q1：
简述线性表的两种存储结构的主要特点。

#### 答案：
线性存储结构在空间上是相邻的，而链表存储结构在空间上是不连续的。

---

### Q2：
简述单链表设置头结点的主要作用。

#### 答案：
使头节点和其他节点的运算保持一致，无需特殊处理。

---

### Q3:
假设某个含有 n 个元素的线性表有以下运算：
1. **查找**：  
   I. 查找序号为 $i$ $(1 \leq i \leq n)$ 的元素。  
   II. 查找第一个值为 $x$ 的元素。
   
2. **插入**：  
   III. 插入新元素作为第一个元素。  
   IV. 插入新元素作为最后一个元素。  
   V. 插入第 $i$ $(2 \leq i \leq n)$ 个元素。

3. **删除**：  
   VI. 删除第一个元素。  
   VII. 删除最后一个元素。  
   VIII. 删除第 $i$ $(2 \leq i \leq n)$个元素。

现设计该线性表的一下存储结构：
1. 顺序表
2. 带头结点的单链表
3. 带头结点的循环单链表
4. 不带头结点且仅有尾结点指针标识的循环单链表
5. 带头结点的双链表
6. 带头结点的循环双链表

指出各种存储结构中对应运算算法的时间复杂度。

#### 答案：
1. 顺序表：
    ```cpp
    struct ArrayList {
    enum {MAX = 50};
      Item a[MAX]; // Item 为储存数据的类型。
      int size;
    };
    ```

    时间复杂度：<br>
    I. $O(1)$ <br>
    II. $O(n)$ <br>
    III. $O(n)$ <br>
    IV. $O(1)$ <br>
    V. $O(n - i)$ <br>
    VI. $O(n)$ <br>
    VII. $O(1)$ <br>
    VIII. $O(n - i)$ <br>

2. 带头结点的单链表：
    ```cpp
    struct SinglyLinkedList {
      Item data;
      Item* next;
    };
    ```

    时间复杂度：<br>
    I. $O(i)$ <br>
    II. $O(n)$ <br>
    III. $O(1)$ <br>
    IV. $O(n)$ <br>
    V. $O(i)$ <br>
    VI. $O(1)$ <br>
    VII. $O(n)$ <br>
    VIII. $O(i)$ <br>

3. 带头结点的循环单链表：
    ```cpp
    struct CircularSinglyLinkedList {
      Item data;
      Item* next;
    };
    ```

    时间复杂度：<br>
    I. $O(i)$ <br>
    II. $O(n)$ <br>
    III. $O(1)$ <br>
    IV. $O(n)$ <br>
    V. $O(i)$ <br>
    VI. $O(1)$ <br>
    VII. $O(n)$ <br>
    VIII. $O(i)$ <br>

4. 不带头结点仅有尾结点指针标识的循环单链表：
    ```cpp
    struct CircularSinglyLinkedListWithTail {
        Item data;
        Item* next;
    };
    ```

    时间复杂度：<br>
    I. $O(i)$ <br>
    II. $O(n)$ <br>
    III. $O(1)$ <br>
    IV. $O(1)$ <br>
    V. $O(i)$ <br>
    VI. $O(1)$ <br>
    VII. $O(n)$ <br>
    VIII. $O(i)$ <br>

5. 带头结点的双链表：
    ```cpp
    struct DoublyLinkedList {
      Item* prior;
      Item data;
      Item* next;
    };
    ```

    时间复杂度：<br>
    I. $O(i)$ <br>
    II. $O(n)$ <br>
    III. $O(1)$ <br>
    IV. $O(n)$ <br>
    V. $O(i)$ <br>
    VI. $O(1)$ <br>
    VII. $O(n)$ <br>
    VIII. $O(i)$ <br>

6. 带头结点的循环双链表：
    ```cpp
    struct CircularDoublyLinkedList {
      Item* prior;
      Item data;
      Item* next;
    };
    ```

    时间复杂度：<br>
    I. $O(i)$ <br>
    II. $O(n)$ <br>
    III. $O(1)$ <br>
    IV. $O(1)$ <br>
    V. $O(i)$ <br>
    VI. $O(1)$ <br>
    VII. $O1)$ <br>
    VIII. $O(i)$ <br>

---

### Q4：
对于顺序表 $L$ ，指出以下算法的功能。
```cpp
void fun(SqList* &L) {
  int i, j = 0;
  for (i = 1; i < L->length; i++)
    if (L->data[i] > L->data[j]) j = i;
  for (i = j; i < L->length - 1; i++)
    L->data[i] = L->data[i + 1];
  L->length--;
} 
```

#### 答案：
删除 $L$ 中最大的元素。

---

### Q5:
对于顺序表L，指出以下算法的功能。
```cpp
void fun(SqList* &L, ElemType x) {
  int i, j = 0;
  for (i = 1; i < L->length; i++)
    if (L->data[i] <= L->data[j]) j = i;
  for (i = L->lenght; i > j; i++)
    L->data[i] = L->data[i - 1];
  L->length++;
} 
```

#### 答案：
在最后一个最小元素前插入 $x$ 。

---

### Q6:
有人设计以下算法用于删除整数顺序表L中所有值在 $[x,y]$ 范围内的元素，该算法显然不是高效的，请设计一个同样功能的高效算法。
```cpp
// 算法复杂度O(n^2)
void fun(SqList* &L, ElemType x, ElemType y) { //题目没有给 y 值，这里补上。
  int i, j;
  for (i = 0; i < L->length; i++)
    if (L->data[i] >= x && L->data[i] <= y) {
          for (j = i; j < L->length - 1; j++)
            L->data[j] = L->data[j + 1];
            L->length--;
        }
} 
```

#### 答案：
```cpp
// 算法复杂度O(n)
void fun(SqList* &L, ElemType x, ElemType y) {
  int k = 0, j;
  for (j = 0; i < L->length; j++)
    if (L->data[j] >= x && L->data[j] <= y) {
      ++k;
      break; // 保证 j 会是第一个满足条件的元素下标。
    }
  for (int i = j + 1; i < L->length; i++) {
    if (!(L->data[i] >= x && L->data[i] <= y)) {
      L->data[j] = L->data[i];
      ++j; 
    } else {
      ++k;
    }
  }
  L->length -= k;
}
```

---

### Q7:
设计一个算法，将元素 $x$ 插入到一个有序（从小到大排序）顺序表的适当位置，并保持有序性。

#### 答案：
```cpp
// 算法复杂度O(logn)，主要算法为二分查找，其他细节会忽略。
void fun(SqList* &L, ElemType x) {
  if (L->length == 0 || x < L->data[0]) {
    insert(L, x, 0);
    return;
  }
  if (x > L->data[L->length - 1]) {
    insert(L, x, L->length);
    return;
  }

  int start = 0, end = L->length - 1, temp;
  while (start < end) {
    temp = (start + end) / 2;
    if (x > L->data[temp]) start = temp + 1;
    else end = temp;
  }
  insert(L, x, start);
}
```

---

### Q8:
假设一个顺序表 $L$ 中的所有元素为整数，设计一个算法调整该顺序表，使其中所有小于零的元素放在所有大于等于零的元素的前面。
```cpp
// 算法复杂度O(n)，和第六题核心算法一样。
void fun(SqList* &L) {
  int j;
  for (j = 0; i < L->length; j++)
    if (L-data[j] >= 0) break; // 保证 j 会是第一个满足条件的元素下标。
  for (int i = j + 1; i < L->length; i++)
    if (!(L-data[i] >= 0)) {
      L->data[j] = L->data[i];
      ++j; 
    }
}
```

---

### Q9:
对于不带头结点的单链表 $L1$ ，其节点类型为 LinkNode ，指出以下算法的功能。
```cpp
void fun(LinkNode*& L1, LinkNode*& L2) {
  int n = 0;
  LinkNode *p = L1;
  while (p != nullptr) {
    ++n;
    p = p->next;
  }
  p = L1;
  for (int i = 1; i < n / 2; ++i) p = p->next;
  L2 = p->next;
  p->next = nullptr;
}
```

#### 答案：
对半拆分 $L1$，$L1$ 指向原 $L1$ 的前半段，$L2$ 指向原 $L1$ 的后半段。

---

### Q10:
在节点类型为 DLinkNode 的双链表中给出将 $p$ 所指节点（非尾节点）与其后继节点交换的操作。

#### 答案：
```cpp
void swap(DLinkNode*& L, DlinkNode* p) {
  const DLinkNode* p1 = p->prior, p2 = p, p3 = p->next, p4 = p->next->next;
  if (p1 != nullptr) p1->next = p3; // 确定 p 不是头节点。 
  p2->prior = p3;
  p2->next = p4;
  p3->prior = p1;
  p3->next = p2;
  if (p4 != nullptr) p4->prior = p3; // 确定 p3 不是尾节点。
}
```

---

### Q11:
有一个线性表其中 $(a_1,a_2,...,a_n)$ ，其中 $n \geq 2$ ，采用带头结点的单链表存储，头节点为 $L$ ，每个结点存放线性表中的一个元素，结点类型为 $(data,next)$ ，现查找某个元素值等于 $x$ 的结点指针，若不存在这样的结点返回 $NULL$ 。分别写出下面 3 种情况的查找语句，要求时间尽量少。

1. 线性表中的元素无序
2. 线性表中的元素按递增有序
3. 线性表中的元素按递减有序

#### 答案：
1. 元素无序：
    ```cpp
    LinkNode* find(LinkNode*& L, ElemType x) {
      LinkNode* p = L->next;
      while (p != nullptr) {
        if (p->data == x) return p;
        p = p->next;
      }
      return nullptr;
    }
    ```

2. 元素按递增有序
    ```cpp
    LinkNode* find(LinkNode*& L, ElemType x) { // 无法直接二分查找。
      LinkNode* p = L->next;
      while (p != nullptr) {
        if (p->data == x) return p;
        if (p->data > x) return nullptr;
        p = p->next;
      }
      return nullptr;
    }
    ```

3. 元素按递减有序：
    ```cpp
    LinkNode* find(LinkNode*& L, ElemType x) { // 无法直接二分查找。
      LinkNode* p = L->next;
      while (p != nullptr) {
        if (p->data == x) return p;
        if (p->data < x) return nullptr;
        p = p->next;
      }
      return nullptr;
    }
    ```

---

### Q12:
设计一个算法，将一个带头结点的数据域依次为 $a_1,a_2,...,a_n(n \geq 3)$ 的单链表的所有结点逆置,即第一个节点数据域变为 $a_n$, 第二个节点的数据域变为 $a_{n-1}......$尾节点的数据域变为 $a_1$ 。

