# 练习题 12

### Q1:
什么是文件的逻辑记录和物理记录？它们有什么区别与联系？

#### 答案：
记录是文件存取操作的基本单位。逻辑记录是按用户观点描述的基本存取单位，物理记录是按外存设备观点描述的基本存取单位。

---

### Q2:
比较顺序文件、索引非顺序文件、索引顺序文件和哈希文件的存储代价、检索、插入及删除记录时的优点和缺点。

#### 答案：
| 文件类型       | 存取特点                     | 优点                | 缺点                      |
|----------------|------------------------------|---------------------|---------------------------|
| 顺序文件       | 仅支持顺序查找，适合批量检索 | 存取速度快          | 插入、删除需复制整个文件  |
| 索引非顺序文件 | 适合随机存取，不适合顺序存取 | 支持随机访问        | 顺序存取效率低            |
| 索引顺序文件   | 支持顺序和随机存取，稀疏索引 | 查找快，占用空间少  | 插入、删除需移动后续记录  |
| 哈希文件       | 基于哈希函数，随机存取       | 存取快，无需索引区  | 不支持顺序存取，需重组    |

---

### Q3:
某职工表文件如下所示，其中以职工号为主关键字。

| 物理地址 | 职工号 | 姓名 | 年龄 | 性别 | 工作时间 | 职称   |
|----------|--------|------|------|------|----------|--------|
| 1        | 105    | 李华 | 36   | 男   | 1997.7   | 副教授 |
| 2        | 125    | 王丽 | 42   | 女   | 1984.7   | 副教授 |
| 3        | 108    | 张英 | 28   | 男   | 1998.7   | 讲师   |
| 4        | 182    | 陈军 | 52   | 男   | 1970.9   | 教授   |
| 5        | 135    | 吴斌 | 25   | 男   | 1999.9   | 助教   |
| 6        | 116    | 章萍 | 58   | 女   | 1965.9   | 教授   |
| 7        | 140    | 华明 | 40   | 男   | 1989.7   | 助教   |

1. 若将职工文件组织成顺序有序文件，请给出文件的存储结构。
2. 若将该文件组织成索引非顺序文件，请给出其索引表结构。
3. 若将该文件组织成多重表文件，请给出主文件结构及性别索引、工作时间索引（只考虑年份）及年龄段（10 岁为一个年龄段）结构。
4. 若将该文件组织成倒排文件，请写出性别索引、职称索引及年龄段索引、组织索引，要求同 (3)。

#### 答案：
1.
| 物理地址 | 职工号 | 姓名 | 年龄 | 性别 | 工作时间 | 职称   |
|----------|--------|------|------|------|----------|--------|
| 1        | 105    | 李华 | 36   | 男   | 1997.7   | 副教授 |
| 2        | 108    | 张英 | 28   | 男   | 1998.7   | 讲师   |
| 3        | 116    | 章萍 | 58   | 女   | 1965.9   | 教授   |
| 4        | 125    | 王丽 | 42   | 女   | 1984.7   | 副教授 |
| 5        | 135    | 吴斌 | 25   | 男   | 1999.9   | 助教   |
| 6        | 140    | 华明 | 40   | 男   | 1989.7   | 助教   |
| 7        | 182    | 陈军 | 52   | 男   | 1970.9   | 教授   |

2. 
| 物理地址 | 职工号 | 物理地址 |
|----------|--------|----------|
| 11       | 105    |    1     |
| 12       | 108    |    3     |
| 13       | 116    |    6     |
| 14       | 125    |    2     |
| 15       | 135    |    5     |
| 16       | 140    |    7     |
| 17       | 182    |    5     |

3.
| 物理地址 | 职工号 | 姓名 | 年龄 | 性别 | 工作时间 | 职称   | 性别链 | 年龄链 | 职称链 |
|----------|--------|------|------|------|----------|--------|--------|--------|--------|
| 1        | 105    | 李华 | 36   | 男   | 1997.7   | 副教授 | 3      | ^      | 2      |
| 2        | 125    | 王丽 | 42   | 女   | 1984.7   | 副教授 | 6      | 7      | ^      |
| 3        | 108    | 张英 | 28   | 男   | 1998.7   | 讲师   | 5      | 5      | 7      |
| 4        | 182    | 陈军 | 52   | 男   | 1970.9   | 教授   | 7      | 6      | 6      |
| 5        | 135    | 吴斌 | 25   | 男   | 1999.9   | 助教   | ^      | ^      | ^      |
| 6        | 116    | 章萍 | 58   | 女   | 1965.9   | 教授   | ^      | ^      | ^      |
| 7        | 140    | 华明 | 40   | 男   | 1989.7   | 讲师   | ^      | ^      | ^      |

| 次关键字 | 性别指针 | 链长 |
|----------|----------|------|
| 男       | 1        | 5    |
| 女       | 2        | 2    |

| 次关键字 | 头指针 | 链长 |
|----------|--------|------|
| 助教     | 5      | 1    |
| 讲师     | 3      | 2    |
| 副教授   | 1      | 2    |
| 教授     | 4      | 2    |

| 次关键字 | 头指针 | 链长 |
|----------|--------|------|
| 20-29    | 3      | 2    |
| 30-39    | 1      | 1    |
| 40-49    | 2      | 2    |
| 50-59    | 4      | 2    |

4.
| 次关键字 |    物理地址   |
|----------|---------------|
| 男       | 1, 3, 4, 5, 7 |
| 女       | 2, 6          |

| 次关键字 | 物理地址 |
|----------|----------|
| 助教     | 5        |
| 讲师     | 3, 7     |
| 副教授   | 1, 2     |
| 教授     | 4, 6     |

| 次关键字 | 物理地址 |
|----------|----------|
| 20-29    | 3, 5     |
| 30-39    | 1        |
| 40-49    | 2, 7     |
| 50-59    | 4, 6     |

---
