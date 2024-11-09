# 练习题9

### Q1:
设有 5 个数据 $do, for, if, repeat, while$ ，他们排在一个有序表中，其查找概率分别是 $p_1 = 0.2, p_2 = 0.15, p_3 = 0.1, p_4 = 0.03, p_5 = 0.01$ ，而查找它们之间不存在的概率分别为 $q_0 = 0.2, q_1 = 0.15, q_2 = 0.2, q_3 = 0.03, q_4 = 0.02, q_5 = 0.01$ ，该有序表如下：

![](../docs/image/9.excs1.png)

#### 答案：
1. 
顺序查找
```mermaid
graph TD
    do-->for
    for-->if
    if-->repeat
    repeat-->while
```

折半查找
```mermaid
graph TD
    if-->for
    if-->repeat
    for-->do
    repeat-->while
```

2. $ASL_1 = 0.97$  $ASL_2 = 1.07$

3. $ASL_1 = 1.02$  $ASL_2 = 1.07$

---

### Q2:
对于有序表 $A[0 .. 10]$ 在等概率的情况下求采用折半查找时成功和不成功的平均查找长度。对于有序表 (12, 18, 24, 35, 47, 50, 62, 83, 90, 115, 134) ，当用折半查找法 90 时需要进行多少词查找可确定成功？查找 47 时需要进行多少次查找可确定成功？查找 100 时需要进行多少次查找才能确定不成功？

#### 答案：
2, 4, 4

---

### Q3:
有以下查找算法：
```cpp
int fun(int a[], int n, int k) {
    for (int i = 0; i < n; i += 2) {
        if (a[i] == k) return i;
    }
    for (int i = 0; i < n; i += 2) {
        if (a[i] == k) return i;
    }
    return -1;
}
```

#### 答案：
1. 在 a[] 中查找 k 。
2. 4, 3
3. -1 8

---

### Q4:
假设一棵二叉排序树的关键字为单个字母，其后序遍历序列为 $ACDBFIJHGE$ ，回答以下问题：
1. 画出该二叉排序树。
2. 求在等概率情况下的查找成功的平均查找长度。
3. 求在等概率情况下的查找不成功的平均查找长度。

#### 答案：
1.
```mermaid
graph TD
    E-->B
    E-->G
    B-->A
    B-->D
    D-->C
    G-->F
    G-->H
    H-->J
    J-->I
```

2. $ASL_1 = 3.6$

3. $ASL_2 = 3.1$

---

### Q5:
证明如果一棵非空二叉树（所有结点值均不相同）的中序遍历序列是从小到大有序的，则该二叉树是一棵二叉排序树。

#### 答案：
由于中序序列呈正序，则根结点的左子树值都小于根结点值，右子树均大于根结点值。符合二叉排序树定义。

---

### Q6:
由 23, 12, 45 关键字构成的二叉排序树有多少棵？其中属于平衡二叉树的有多少棵？

#### 答案：
3 1

---

### Q7:
将整数序列 (4, 5, 7, 2, 1, 3, 6) 中的元素依次插入一棵空的二叉排序树中，试构造相应的二叉排序树，要求用图形给出构造过程。

#### 答案：
<div style="display: flex; gap: 20px; flex-wrap: wrap;">

1. 
```mermaid
graph TD
   3 
```

2. 
```mermaid
graph TD
    4-->5
```

3.
```mermaid
graph TD
    4-->5
    5-->7
```

4.
```mermaid
graph TD
    4-->5
    5-->7
    4-->2
```

5.
```mermaid
graph TD
    4-->5
    5-->7
    4-->2
    2-->1
```

6.
```mermaid
graph TD
    4-->5
    5-->7
    4-->2
    2-->1
    2-->3
```

7.
```mermaid
graph TD
    4-->5
    5-->7
    4-->2
    2-->1
    2-->3
    7-->6
```
<div>

---

### Q8:
将整数序列 (4, 5, 7, 2, 1, 3, 6) 中的元素依次插入一棵空的二叉排序树中，试构造相应的二叉排序树，要求用图形给出构造过程。

#### 答案：
<div style="display: flex; gap: 20px; flex-wrap: wrap;">

1. 
```mermaid
graph TD
   3 
```

2. 
```mermaid
graph TD
    4-->5
```

3. 4 失衡
```mermaid
graph TD
    4-->5
    5-->7
```

4. 左旋平衡
```mermaid
graph TD
    5-->4
    5-->7
```
5.
```mermaid
graph TD
    5-->4
    5-->7
    4-->2
```

6. 4 失衡
```mermaid
graph TD
    5-->4
    5-->7
    4-->2
    2-->1
```

7. 右旋平衡
```mermaid
graph TD
    5-->7
    5-->2
    2-->1
    2-->4
```

8. 5 失衡
```mermaid
graph TD
    5-->7
    5-->2
    2-->1
    2-->4
    4-->3
```

9. 先 2 左旋 5 再右旋
```mermaid
graph TD
    4-->2
    2-->1
    2-->3
    4-->5
    5-->7
```

10. 5 失衡 
```mermaid
graph TD
    4-->2
    2-->1
    2-->3
    4-->5
    5-->7
    7-->6
```

11. 5 左旋 
```mermaid
graph TD
    4-->2
    2-->1
    2-->3
    4-->7
    7-->5
    7-->6
```
<div>

---

### Q9:
有一个关键字序列为 (11, 14, 2, 7, 1, 15, 5, 8, 4) ，从一棵空红黑树开始依次插入各个关键字创建一棵红黑树，给出创建红黑树的这个过程。

#### 答案：
<div style="display: flex; gap: 20px; flex-wrap: wrap;">

1. 
```mermaid
graph TD;
    11;

    classDef redNode fill:#ff0000,color:#000000;
```

2.
```mermaid
graph TD;
    11-->14;

    class 14 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

3.
```mermaid
graph TD;
    11-->2;
    11-->14;

    class 2,14 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

4. 红色属性冲突
```mermaid
graph TD;
    11-->2;
    11-->14;
    2-->7;

    class 2,7,14 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

5. 结点 2, 11, 14 变色。根属性冲突
```mermaid
graph TD;
    11-->2;
    11-->14;
    2-->7;

    class 7,11 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

6. 结点 11 变色。
```mermaid
graph TD;
    11-->2;
    11-->14;
    2-->7;

    class 7 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

7. 
```mermaid
graph TD;
    11-->2;
    11-->14;
    2-->1;
    2-->7;

    class 1,7 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

8. 
```mermaid
graph TD;
    11-->2;
    11-->14;
    14-->15;
    2-->1;
    2-->7;

    class 1,7,15 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

8. 红色属性冲突
```mermaid
graph TD;
    11-->2;
    11-->14;
    14-->15;
    2-->1;
    2-->7;
    7-->5;

    class 1,5,7,15 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

9. 结点 1, 2, 7 变色
```mermaid
graph TD;
    11-->2;
    11-->14;
    14-->15;
    2-->1;
    2-->7;
    7-->5;

    class 2,5,15 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

10.
```mermaid
graph TD;
    11-->2;
    11-->14;
    14-->15;
    2-->1;
    2-->7;
    7-->5;
    7-->8;

    class 2,5,8,15 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

11. 红色属性冲突
```mermaid
graph TD;
    11-->2;
    11-->14;
    14-->15;
    2-->1;
    2-->7;
    7-->5;
    7-->8;
    5-->4;

    class 2,4,5,8,15 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

12. 结点 5, 7, 8 变色。继续冲突
```mermaid
graph TD;
    11-->2;
    11-->14;
    14-->15;
    2-->1;
    2-->7;
    7-->5;
    7-->8;
    5-->4;

    class 2,4,7,15 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```

12. 左旋结点 2 ，结点 7, 11 变色，右旋结点 11
```mermaid
graph TD;
    11-->8;
    11-->14;
    14-->15;
    2-->1;
    2-->5;
    7-->2;
    7-->11;
    5-->4;

    class 2,4,11,15 redNode;
    classDef redNode fill:#ff0000,color:#000000;
```
