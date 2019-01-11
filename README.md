# C++ Data Structures and Algorithms  数据结构和算法
This is the code repository for [C++ Data Structures and Algorithms](https://www.packtpub.com/application-development/c-data-structures-and-algorithms?utm_source=github&utm_medium=repository&utm_campaign=9781788835213), published by [Packt](https://www.packtpub.com/?utm_source=github). It contains all the supporting project files necessary to work through the book from start to finish.
## About the Book
C++ is a general-purpose programming language which has evolved over the years and is used to develop software for many different sectors. This book will be your companion as it takes you through implementing classic data structures and algorithms to help you get up and running as a confident C++ programmer.


## Instructions and Navigation
All of the code is organized into folders. Each folder starts with a number followed by the application name. For example, Chapter02.

All code files are present in their respective folder.

The code will look like the following:
```
// in_out.cpp
#include <iostream>
  int main ()
  {
     int i;
     std::cout << "Please enter an integer value: ";
     std::cin >> i;
     std::cout << "The value you entered is " << i;
     std::cout << "\n";
     return 0;
   }
```

To get through this book and successfully complete all the source code examples, you will
need the following specifications:
* Desktop PC or Notebook with Windows, Linux, or macOS
* GNU GCC v5.4.0 or above
* Code::Block IDE v17.12 (for Windows and Linux OS) or Code::Block IDE v13.12
(for macOS)

## Related Products
* [C++ High Performance](https://www.packtpub.com/application-development/c-high-performance?utm_source=github&utm_medium=repository&utm_campaign=9781787120952)

* [Mastering the C++17 STL](https://www.packtpub.com/application-development/mastering-c17-stl?utm_source=github&utm_medium=repository&utm_campaign=9781787126824)

* [Learning C++ Functional Programming](https://www.packtpub.com/application-development/learning-c-functional-programming?utm_source=github&utm_medium=repository&utm_campaign=9781787281974)

# 程序分析
## 章1 基础知识======================================
### 1.1 C++基础
### 1.2 抽象数据结构 abstract data type
### 1.3 算法分析 

## 章2 列表List & 链表 Linked List===================
### 2.1 列表

### 2.2 单向链表

### 2.3 双向链表

## 章3 Stack栈 和 队列Queue===========================
### 3.1 Stack栈
### 3.2 队列Queue

### 3.3 双端队列 Double Queue

## 章4 排序算法 arranging 冒泡选择插入归并快排 ========
### 4.1 冒泡 Bubble 
### 4.2 选择 Selection
### 4.3 插入 Insert
### 4.4 归并 Merge
### 4.5 快排 Quick
### 4.6 计数 Counting
### 4.7 基数 Radix

## 章5 查找算法 Searching 线性二分====================
### 5.1 线性 Linear search
### 5.2 二分 Binary search
### 5.3 三分 Ternary search
### 5.4 插补 Interpolation Search 
### 5.5 跳跃 Jump Search 
### 5.6 指数 Exponential search
### 5.7 子表 Sublist search

## 章6 String 字符数据算法===========================

## 章7 树结构算法 Tree==============================
### 7.1 二叉树(Binary Tree)
[参考](https://www.cnblogs.com/eudiwffe/p/6207196.html)
```c
/*   A simple binary tree
 *        A ---------> A is root node
 *       / \
 *      /   \
 *     B     C
 *    /     / \
 *   /     /   \
 *   D     E    F ---> leaves: D, E, F
 *
 *       (1)      ---> Height: 3
 * */
```

    二叉树（Binary Tree）是最简单的树形数据结构，然而却十分精妙。
    其衍生出各种算法，以致于占据了数据结构的半壁江山。
    STL中大名顶顶的关联容器——集合（set）、映射（map）便是使用二叉树实现。
    二叉树的根节点入度为0，叶子节点出度为0。
    
    与楼房一样，一般会对二叉树分层，并且通常将根节点视为第一层。
    接下来B与C同属第二层，D, E, F同属第三层。注意，并不是所有的叶子都在同一层。
    通常将二叉树节点的最高层数作为其树的高度，上例中二叉树高度为3。
    显然，一个二叉树的节点总数必然小于2的树高幂，
    转化成公式表示为：N<2^H，其中N为节点总数，H为二叉树高度；对于第k层，最多有2^(k-1)个节点。
    
    
### 7.2 二叉搜索树(Binary Search Tree)
### 7.3 平衡二叉搜索树  balanced BST (AVL)
### 7.4 二叉堆(Binary heap)
[参考](https://blog.csdn.net/Colton_Null/article/details/80963217)


## 章8 哈希算法 Hash===============================
### 8.1 hash tables
### 8.2
### 8.3 
### 8.4


## 章9 常用算法Real Life 贪婪&分治&动态规划&暴力&随机&回溯====
### 9.1 贪婪 Greedy algorithms
### 9.2 分治 Divide and conquer algorithms
### 9.3 动态规划 Dynamic programming
### 9.4 暴力 Brute-force algorithms
### 9.5 随机 Randomized algorithms
### 9.6 回溯 Backtracking algorithms
