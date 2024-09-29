# 练习题2

### Q1：
简述线性表的两种存储结构的主要特点。

#### 答案：
线性存储结构在空间上是相邻的，而链表存储结构在空间上是不连续的。

---

### Q2：
简述单链表设置头结点的主要作用。

#### 答案：
使头节点和其他节点的运算保持一致，例如删除操作，无需特殊处理。

使空表和非空表的处理统一，例如判断条件只需要 $L->next = nullptr$ 即可，而不需额外判断 $L == nullptr$ 。

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

指出各种存储结构中对应运算算法的（最坏）时间复杂度。

#### 答案：
1. 时间复杂度：<br>
   I. $O(1)$ <br>
   II. $O(n)$ <br>
   III. $O(n)$ <br>
   IV. $O(1)$ <br>
   V. $O(n)$ <br>
   VI. $O(n)$ <br>
   VII. $O(1)$ <br>
   VIII. $O(n)$ <br>

2. 时间复杂度：<br>
   I. $O(n)$ <br>
   II. $O(n)$ <br>
   III. $O(1)$ <br>
   IV. $O(n)$ <br>
   V. $O(n)$ <br>
   VI. $O(1)$ <br>
   VII. $O(n)$ <br>
   VIII. $O(n)$ <br>

3. 时间复杂度：<br>
   I. $O(n)$ <br>
   II. $O(n)$ <br>
   III. $O(1)$ <br>
   IV. $O(n)$ <br>
   V. $O(n)$ <br>
   VI. $O(1)$ <br>
   VII. $O(n)$ <br>
   VIII. $O(n)$ <br>

4. 时间复杂度：<br>
   I. $O(n)$ <br>
   II. $O(n)$ <br>
   III. $O(1)$ <br>
   IV. $O(1)$ <br>
   V. $O(n)$ <br>
   VI. $O(1)$ <br>
   VII. $O(n)$ <br>
   VIII. $O(n)$ <br>

5. 时间复杂度：<br>
   I. $O(n)$ <br>
   II. $O(n)$ <br>
   III. $O(1)$ <br>
   IV. $O(n)$ <br>
   V. $O(n)$ <br>
   VI. $O(1)$ <br>
   VII. $O(n)$ <br>
   VIII. $O(n)$ <br>

6. 时间复杂度：<br>
   I. $O(n)$ <br>
   II. $O(n)$ <br>
   III. $O(1)$ <br>
   IV. $O(1)$ <br>
   V. $O(n)$ <br>
   VI. $O(1)$ <br>
   VII. $O1)$ <br>
   VIII. $O(n)$ <br>

---

### Q4：
对于顺序表 $L$ ，指出以下算法的功能。
```cpp
void fun(SqList*& L) {
  int i, j = 0;
  for (i = 1; i < L->length; i++)
    if (L->data[i] > L->data[j]) j = i;
  for (i = j; i < L->length - 1; i++)
    L->data[i] = L->data[i + 1];
  L->length--;
} 
```

#### 答案：
删除 $L$ 中第一个最大的元素。

---

### Q5:
对于顺序表L，指出以下算法的功能。
```cpp
void fun(SqList*& L, ElemType x) {
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
void fun(SqList*& L, ElemType x, ElemType y) { //题目没有给 y 值，这里补上。
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
void fun(SqList*& L, ElemType x, ElemType y) {
  int k = 0;
  for (int i = 0; i < L->length; i++) // 分界算法
    if (L->data[i] >= x && L->data[i] <= y)
      L->data[k++] = L->data[i];
  L->length = k;
}
```

---

### Q7:
设计一个算法，将元素 $x$ 插入到一个有序（从小到大排序）顺序表的适当位置，并保持有序性。

#### 答案：
```cpp
// 算法复杂度O(n)，不建议使用二分查找，因为后面还要插入值，最坏复杂度会达到 O(nlogn) 。
void fun(SqList*& L, ElemType x) {
  int i = 0;
  while (i < L->length && L->data[i] < x) i++;
  for (int j = L->length - 1; j >= i; --j) 
    L->data[j + 1] = L->data[j];
  L->data[i] = x;
  ++L->length;
}
```

---

### Q8:
假设一个顺序表 $L$ 中的所有元素为整数，设计一个算法调整该顺序表，使其中所有小于零的元素放在所有大于等于零的元素的前面。
```cpp
// 算法复杂度O(n)，和第六题核心算法一样。双指针也可以做。
void fun(SqList*& L) {
  int k = 0;
  for (int i = 0; i < L->length; ++i)
    if (L->data[i] < 0)
      swap(L->data[k++] = L->data[i]);
}
```

---

### Q9:
对于不带头结点的单链表 $L1$ ，其节点类型为 LinkNode ，指出以下算法的功能。
```cpp
void fun(LinkNode*& L1, LinkNode*& L2) {
  int n = 0;
  LinkNode* p = L1;
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
  DLinkNode* p1 = p->prior; 
  DLinkNode* p2 = p;
  DLinkNode* p3 = p->next;
  DLinkNode* p4 = p->next->next;
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
      while (p != nullptr && p->data != x) p = p->next; // 寻找第 1 个符合某条件的位置用这个语句很简洁。
      return p;
    }
    ```

2. 元素按递增有序
    ```cpp
    LinkNode* find(LinkNode*& L, ElemType x) { // 无法直接二分查找。
      LinkNode* p = L->next;
      while (p != nullptr && p->data < x) p = p->next;
      if (p == nullptr || p->data != x) return nullptr;
      return p;
    }
    ```

3. 元素按递减有序：
    ```cpp
    LinkNode* find(LinkNode*& L, ElemType x) { // 无法直接二分查找。
      LinkNode* p = L->next;
      while (p != nullptr && p->data > x) p = p->next;
      if (p == nullptr || p->data != x) return nullptr;
      return p;
    }
    ```

---

### Q12:
设计一个算法，将一个带头结点的数据域依次为 $a_1,a_2,...,a_n(n \geq 3)$ 的单链表的所有结点逆置,即第一个节点数据域变为 $a_n$, 第二个节点的数据域变为 $a_{n-1}......$尾节点的数据域变为 $a_1$ 。

#### 答案：
```cpp
void fun1(LinkNode*& L) {
  LinkNode* left = L;
  LinkNode* middle = L->next;
  LinkNode* right = L->next->next;
  while (right != nullptr) {
    middle->next = left;
    left = middle;
    middle = right;
    right = right->next;
  }
  middle->next = left;
  L->next->next = nullptr; // 尾节点指向 nullptr 。
  L->next = middle; // 头节点指向原尾节点。
}

void fun2(LinkNode*& L) { // 使用头插法。 更少的变量和语句。
  LinkNode* p = L->next;
  LinkNode* q;
  L->next = nullptr; // 设置空表。
  while (p != nullptr) {
    q = p->next;
    p->next = L->next;
    L->next = p;
    p = q;
}
```

---

### Q13:
一个线性表 $(a_1,a_2,...,a_n) (n \gt 3)$ 采用带头结点的单链表 $L$ 存储，设计一个高效算法求中间位置的元素（即序号为 $[n/2]$ 的元素）。

#### 答案：
```cpp
ElemType fun(LinkNode*& L) {
  LinkNode* slow = L;
  LinkNode* fast = L; // 快慢指针
  while (fast->next == nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}
```

---

### Q14:
设计一个算法在带头结点的非空链表 $L$ ，中第一个最大值结点（最大值结点可能有多个）之前插入一个值为 $x$ 的结点。

#### 答案：
```cpp
void fun(LinkNode*& L, ElemType x) {
  LinkNode* max = L->next;
  for (LinkNode* i = L->next; i != nullptr; i = i->next)
    if (i->data > max->data) max = i;
  insert(L, x, max); // 在 L 链表 max 节点前插入值为 x 的新结点。
}
```

---

### Q15:
设有一个带头结点的单链表 $L$ ，结点的结构为 $(data,next)$ ，其中 $data$ 为正数元素， $next$ 为后继结点的指针。设计一个算法，首先按递减次序输出该单链表中各结点的数据元素，然后释放所有结点占用的存储空间，并要求算法的空间复杂度为 $O(1)$ 。

#### 答案：
```cpp
void fun(LinkNode*& L) { // 保证 L 的实参指向 nullptr 。
  LinkNode* end = nullptr;
  if (L->next == nullptr) return;
  while (end != L->next->next) { // 冒泡排序。
    LinkNode* p1 = L;
    LinkNode* p2 = p1->next;
    LinkNode* p3 = p3->next;
    LinkNode* p4 = p4->next;
    while (p3 != end) {
      if (p2->data > p3->data) { // 节点交换。
        p1->next = p3;
        p3->next = p2;
        p2->next = p4;
        p2 = p1->next;
        p3 = p2->next;
        
      }
      p1 = p1->next, p2 = p2->next, p3 = p3->next;
      if (p4 != nullptr) p4 = p4->next;
    }
    end = p2;
  }
  LinkNode* left = L;
  LinkNode* right = L->next; // 打印并销毁。
  while (right != nullptr) {
    cout << right->data << "\n";
    free(left);
    left = right, right = right->next;
  }
  free(left);
  L = nullptr;
}
```

---

### Q16:
设有一个双链表 $h$ ，每个结点中除了有$prior, data 和 next$ 几个域以外，还有一个访问频度域 $freq$，在链表被启用之前，其值均初始化为零。每当进行 $LocateNode(h,x)$ 运算时，令元素值为 $x$ 的节点中 $freq$ 域的值加一，并调整表中结点的次序，使其按访问频度的递减次序排列，以便使频繁访问的结点总是靠近表头。试写一个符合上诉要求的 $LocateNode$ 运算的算法。

#### 答案：
```cpp
void LocateNode(DLinkNode*& h, ElemType x) { // 简单起见，认为值为 x 的结点有且仅有一个。
  DLinkNode* x_ptr = h->next;
  DLinkNode* freq_equal = h->next; // 指向第一个频度和 x_ptr 指向的频度大小相同的结点。
  while (x_ptr->data != x) {
    x_ptr = x_ptr->next;
    if (freq_equal->freq != x_ptr->freq) freq_equal = x_ptr;
  }
  if (freq_equal != x_ptr) { // 交换结点。
    if (freq_equal->next != x_ptr) {
      DLinkNode* fe_left = freq_equal->prior;
      DLinkNode* fe_right = freq_equal->next;
      DLinkNode* xp_left = x_ptr->prior;
      DLinkNode* xp_right = x_ptr->next;
      fe_left->next = x_ptr;
      fe_right->prior = x_ptr;
      x_ptr->prior = fe_left;
      x_ptr->next = fe_right;
      xp_left->next = freq_equal;
      if (xp_right != nullptr) xp_right->right = freq_rqual;
      freq_equal->prior = xp_left;
      freq_equal->next = xp_right;
    } else {
      DLinkNode* fe_left = freq_equal->prior;
      DLinkNode* xp_right = x_ptr->next;
      fe_left->next = x_ptr;
      x_ptr->prior = fe_left;
      x_ptr->next = freq_equal;
      if (xp_right != nullptr) xp_right->prior = freq_equal;
      freq_equal->prior = x_ptr;
      freq_equal->next = xp_right;
    }
  }
  ++x_ptr->freq;
}
```

---

### Q17:
设 $ha = (a_1, a_2, ... , a_n)$ 和 $hb = (b_1, b_2, ... , b_m)$ 是两个带头结点的循环单链表，设计一个算法将这两个表合并为带头结点的循环单链表 $hc$ 。

#### 答案：
```cpp
void fun(CLinkNode* hc, CLinkNode* ha, CLinkNode* hb) {
  auto p = ha;
  while (p->next != ha) p = p->next;
  p->next = hb->next;
  while (p->next != hb) p = p->next;
  p->next = hc;
  hc->next = ha->next;
}
```

---

### Q18:
设两个非空线性表分别用带头结点的循环双链表 $ha$ 和 $hb$ 表示，设计一个算法 $Insert(ha,hb,i)$ ，其功能是当 $i = 0$ 时将 $hb$ 插到 $ha$ 的前面；当 $i \gt 0$ 时将 $hb$ 插到 $ha$ 中第 $i$ 个结点的后面；当 $i$ 大于等于 $ha$ 的长度时将 $hb$ 插到 $ha$ 的前面。 

#### 答案：
```cpp
void Insert(DCLinkNode* ha, DCLinkNode*& hb, int i) { // 不考虑删除头节点。
  auto ha_rear = ha->prior;
  auto hb_rear = hb->prior;
  if (i == 0) {
    ha->next->prior = hb_rear;
    hb_rear->next = ha->next;
    hb->next->prior = ha;
    ha->next = hb->next; // ha 仍为头结点。
  }
  if (i > 0) {
    int ha_length = 1;
    for (auto j = ha->next; j != ha; j = j->next) ++ha_length;
    if (i >= ha_length) {
      hb->next->prior = ha_rear;
      ha_rear->next = hb->next;
      hb_rear->next = ha;
      ha->prior = hb_rear;
    } else {
      auto temp = ha->next;
      for (int j = 0; j < i; ++j) temp = temp->next;
      auto temp_right = temp->next;
      temp_right->prior = hb-rear;
      hb_rear->next = temp->right;
      temp->next = hb->next;
      hb->next->prior = temp;
    }
  }
  hb = nullptr;
  delete hb;
}
```

---

### Q19:
用带头结点的单链表表示整数集合，完成以下算法并分析时间复杂度：
1. 设计一个算法求两个集合 $A$ 和 $B$ 的并集运算，即 $C = A \cup B$ ，要求不破环原有的单链表 $A$ 和 $B$ 。
2. 假设集合中的元素按递增排列，设计一个高效的算法求两个集合 $A$ 和 $B$ 的并集运算，即 $C = A \cup B$ ，要求不破环原有的单链表 $A$ 和 $B$ 。

#### 答案：
1. 无序：
    ```cpp
    void fun(LinkNode*& C, LinkNode* A, LinkNode* B) {
      C = new LinkNode;
      auto c_rear = C;
      for (auto i = A->next; i != nullptr; i = i->next) {
        c_rear->next = new LinkNode;
        c_rear = c_rear->next;
        c_rear->data = i->data;
      }
      c_rear->next = nullptr
      for (auto i = B->next; i != nullptr; i = i->next)
        if (!has(A, i)) { // 如果 i->data 在 A 链表中则返回 true ，反之 false。
        c_rear->next = new LinkNode;
        c_rear = c_rear->next;
        c_rear->data = i->data;
        }
      c_rear->next = nullptr
    }
    ```

2. 递增：
    ```cpp
    void fun(LinkNode*& C, LinkNode* A, LinkNode* B) {
      auto c_rear = C;
      auto i = A->next;
      auto j = B->next;
      while (i != nullptr && j != nullptr) {
        if (i->data < j->data) {
          c_rear->next = new LinkNode;
          c_rear = c_rear->next;
          c_rear->data = i->data;
          i = i->next;
        } else if (i->data > j->data) {
          c_rear->next = new LinkNode;
          c_rear = c_rear->next;
          c_rear->data = j->data;
          j = j->next;
        } else {
          c_rear->next = new LinkNode;
          c_rear = c_rear->next;
          c_rear->data = j->data;
          i = i->next, j = j->next;
        }
      }
      while (i != nullptr) {
        c_rear->next = new LinkNode;
        c_rear = c_rear->next;
        c_rear->data = i->data;
        i = i->next;
      } 
      while (j != nullptr) {
          c_rear->next = new LinkNode;
          c_rear = c_rear->next;
          c_rear->data = j->data;
          j = j->next;
      }
      c_rear->next = nullptr;
    }
    ```

---

### Q20:
用带头结点的单链表表示整数集合，完成以下算法并分析时间复杂度：
1. 设计一个算法求两个集合 $A$ 和 $B$ 的差集运算， 即 $C = A - B$ ，要求算法的空间复杂度为 $O(1)$ ，并释放单链表 $A$ 和 $B$ 不需要（删掉不影响结果）的结点。
2. 假设集合中的元素按递增排列，设计一个高效的算法求两个集合 $A$ 和 $B$ 的差集运算，即，$C = A - B$ ，要求算法的空间复杂度为 $O(1)$ ，并释放单链表 $A$ 和 $B$ 不需要（删掉不影响结果）的结点。

#### 答案：
1. 无序：
    ```cpp
    SetDiff(LinkNode*& C, LinkNode* A, LinkNode* B) {
      auto c_rear = C;
      auto temp;
      for (auto i = A->next, i_left = A; i != nullptr; i = i->i-next, i_left = i_left->next) {
        if (!has(B, i->data)) { // 如果 i->data 在 B 中返回 true，反之 false 。
          c_rear->next = new LinkNode;
          c_rear = c_rear->next;
          c_rear->data = i->data;
        } else {
          temp = i;
          i = i->next;
          i_left->next = i;
          delete temp;
        }
      }
      auto b = B;
      while (b != nullptr) {
        temp = b;
        b = b->next;
        delete temp;
      }
    }
    ```

2. 递增：
    ```cpp
    void SetDiff(LinkNode*& C, LinkNode* A, LinkNode* B) {
      auto c_rear = C;
      auto i_left = A;
      LinkNode* temp;
      auto i = A->next;
      auto j = B->next;
      while (i && j) {
        if (i->data < j->data) {
          c_rear->next = new LinkNode;
          c_rear = c_rear->next;
          c_rear->data = i->data;
          i = i->next;
          i_left = i_left->next;
        } else if (i->data > j->data) {
          j = j->next;
        } else {
          temp = i;
          i = i->next;
          i_left->next = i;
          delete temp;
          j = j->next;
        }
      }
      while (i) {
          c_rear->next = new LinkNode;
          c_rear = c_rear->next;
          c_rear->data = i->data;
          i = i->next;
      }
      c_rear->next = nullptr;
      auto b = B;
      while (b != nullptr) {
        temp = b;
        b = b->next;
        delete temp;
      }
    }

    ```

---
