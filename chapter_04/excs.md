# 练习题4

### Q1:
串是一种特殊的线性表，请从存储和运算两方面分析它的特殊之处。

#### 答案：
串仅以字符为单位存储，运算多涉及子串而非单个字符的操作。

---

### Q2:
为什么在模式匹配中 $BF$ 算法是有回溯算法，而 $KMP$ 算法是无回溯算法？

#### 答案：
$KMP$ 算法通过计算 $next$ 得到了正在匹配的字符不匹配时，主串前面有多少个字符与子串前端字符匹配，而 $BF$ 算法没有 $next$ ， 只好通过回溯来确定有多少字符匹配。

---

### Q3:
在 $KMP$ 算法中计算模式串的 $next$ 时，若 $j = 0$ ， 为什么要设置 $next[0] = -1$ ？

#### 答案：
说明字符串 [0] 前面没有字符了，相似度为 -1 ，实际上取 0 也可以。如果大于 0 ，当后面通过 $next$ 赋值 $j$ 时就会出现问题。

---

### Q4:
$KMP$ 算法是简单模式匹配算法的改进，以目标串 $s = "aabaaabc"$ 、模式串 $t = "aaabc"$ 为例说明 $next$ 的作用。

#### 答案：
匹配字符串，如果匹配成功则 $i，j$ 同时往前进一位，如果匹配失败则 $i$ 不移动，$j$ 改变。在这里如果时朴素匹配算法的话 $j$ 将重置为 0 ，而通过 $next$ 我们可以知道当前子串（ 匹配串中 $j$ 前的子串）$j$ 前面有几个字符与子串开头的字符完全相同，这样我们将 $j$ 设置为第一个不相同的字符的下标（即 $next$），就可以减少匹配的次数 。

例如上例，我们计算得到 $next = [-1, 0, 1, 2, 0]$ 。第一次匹配到 $i, j =2$ 时匹配不上。我们通过 $next$ 可以知道 $j = 2$ 时 $j$ 前面有两个字符与匹配串前端字符相同。又因为 $j = 2$ 就是之前匹配不上的字符，所以我们将 $j$ 设为 $1$。循环这个过程一次发现连 $j = 0$ 也匹配不上，将 $i$ 进一位重新开始匹配。

在进行上述过程时我们会发现这三次重设 $j$ 实际上是多余的，因为这几个位置最后不匹配的字符是相同的，当 $j = 2$ 代表的字符不匹配时 $j = 0, 1$ 对应的字符也一定不匹配。所以我们还可以优化一下 $KMP$ 算法，在 $j = k$ 时对应的字符不匹配时，我们需要知道这个字符第一个相同的字符下标所对应的相似度 $next$，我们在计算 $next$ 时直接让 $j = k$ 的$next $ 值为第一个相同字符对应的相似度。

根据上例，我们重新计算得到 $next = [-1, -1, -1, 2, 0]$ 。 第一次匹配失败，由于只有 $j =0$ 的 $next = -1$ ，而现在 $j = 2$ 的 $next$ 也等于 $-1$ , 说明 $j = 0 和 j = 2$的字符一样，这里我们直接让 $i$ 进一位。

---

### Q5:
给出以下模式串的 $next$ 值和 $nextval$ 值。
1. $ababaa$
2. $abaabaab$

#### 答案：
1. $next = [-1, 0, 0, 1, 2, 3]$<br>$nextval = [-1, 0, -1, 0, -1, 3]$
2. $next = [-1, 0, 0, 1, 1, 2, 3, 4]$<br>$nextval = [-1, 0, -1, 1, 0, -1, 1, 0]$

---

### Q6:
设目标串 $s = "abcaabbabcabaacbacba", 模式串 $t = "abcabaa"$ 。
1. 计算模式串 $t$ 的 $nextval$ 数组。
2. 不写算法，给出利用改进的 $KMP$ 算法进行匹配的过程。
3. 总共进行了多少次字符比较？

#### 答案：
1. $nextval = [-1, 0, 0, -1, 0, 2, 1]$
2. 匹配过程：
   - 第一次匹配：在 i = 4, j = 4 时匹配失败，j 设为 0;
   - 第二次匹配：在 i = 6, j = 2 时匹配失败，j 设为 0;
   - 第三次匹配：在 i = 6, j = 0 时匹配失败，++i;
   - 第四次匹配：在 i = 14，j = 7 时匹配成功。
3. 16 次

---

### Q7:
有两个顺序串 s1 和 s2 ，设计一个算法求顺序串 s3， 该串中的字符是 s1 和 s2 中的公共字符（即两个串都包含的字符）。

#### 答案：
```cpp
void fun(SqString& s1, SqString& s2, SqString& s3) {
  for (auto i = 0; i != s1.Size(); ++i)
    if (s2.Find(s1[i])) s3.Push(*cur);
}
```

---

### Q8:
采用顺序结构存储串，设计一个实现串通配符匹配的算法 pattern_index(), 其中通配符只有'?'，他可以和任何一个字符匹配成功，例如，pattern_index("?re", "there are") 返回的结果是 2 。

#### 答案：
```cpp
//  至少对"?re", "there are" 是没问题的。:D
int pattern_index(const char* match, const char* master) {
  int length = 0;
  while (match[length] != '\0') ++length;
  int* nextval = new int[size(match)]; 
  nextval[0] = -1;
  int i = 0, j = -1;
  while (i < size(match)) {
    if (j == -1 || match[j] == match[i] || match[j] == '?' || match[i] == '?') {
      ++i, ++j;
      nextval[i] = (match[j] != match[i]) ? j : nextval[j];
    } else {
      j = nextval[j];
    }
  }
  i = 0, j = 0;
  while (i < size(master) && j != size(match)) {
    if (j == -1 || match[j] == '?' || master[i] == match[j]) {
      ++i, j++;
    } else {
      j = nextval[j];
    }
  }
  delete[] nextval;
  if (j == size(match) return i - j;
  return -1;
}
```

---

### Q9:
设计一个算法，在顺序串 $s$ 中从后往前的查找子串 $t$ ，即求 $t$ 在 $s$ 中最后一次出现的位置。

#### 答案：
```cpp
int last_find(const char* match, const char* master) {
  const char* temp1 = reverse(match);
  const char* temp2 = reverse(master);
  return size(temp2) - (pattern_index(temp1, temp2) + size(match));
}
```

---

### Q10:
设计一个算法，判断一个字符串 $s$ 是否为形如”序列 $1$ @ 序列 $2$ ”模式的字符序列，其中序列 $1$ 和 序列 $2$ 都不含有 '@' 字符，且序列 $2$ 是序列 $1$ 的逆序列。例如 "a+b@b+a" 属于该模式的字符序列，而 "1+3@3-1"不是。

#### 答案：
```cpp
bool IsConform(const char* str) {
  int divide;
  if ((divide = patern_index('@', str)) == -1) return false;
  if (divide != size(str) - divide - 1) return false;
  for (int i = 0; i != divide; ++i)
    if (str[i] != str[size(str) - i - 1]) return false;
  return true;
}
```

---

### Q11:
采用顺序结构存储串，设计一个算法求串 $s$ 中出现的第一个最长重复出现的子串的下标和长度。

#### 答案：
```cpp
void LongestRptStr(const char* s) {
  int max_index = 0, max_length = 0, cur_length = 0;
  for (int i = 0; i < size(s); ++i) {
    for (int j = i + 1; j < size(s); ++j) {
      if (s[i] == s[j]) {
        cur_length = 1;
        for (int k = 1; s[i + k] == s[j + k]; ++k) ++cur_length;
        if (max_length < cur_length) {
          max_index = i + 1 - cur_length;
          max_length = cur_length;
        }
        j += len, --j;
      }
    }
  }
  cout << "max_index: " << max_index << "\nmax_length: " << max_length << "\n";
}
```

---

### Q12:
采用带头结点的单链表表示链串，每个结点存放一个字符，设计一个算法，将链串 $s$ 中所有值为 $x$ 的字符删除，要求算法的时间复杂度为 $O(n)$ 、空间复杂度为 $O(1)$ 。

#### 答案：
```cpp
void DeleteX(LinkString& s, char x) {
  auto cur = s.Begin();
  while (cur != s.End())
    if (cur.data == x) 
      s.Erase(cur);
    else
      cur = cur->next;
}
```

---
