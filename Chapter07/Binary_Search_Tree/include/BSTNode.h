// Project: Binary_Search_Tree.cbp
// File   : BSTNode.h 二叉搜索树，左子树<=父节点<=右子树
/*
// BST任何一颗子树上的三个节点left, parent, right. 满足条件left.key<parent.key<=right.key，
// 一颗典型的BST如下图所示：
//    /  6   \
//  / 5 \    7 \
// 2     5      8
// 观察之后不难发现如果对BST进行PREORDER walk(先序遍历)，得到：2, 5, 5, 6, 7, 8 刚好是升序排列。
// 所谓PREORDER walk，就是要访问以ROOT为根的树，先要访问ROOT.left, 然后访问ROOT, 最后访问ROOT.right。
之所以称为二叉搜索树，是因为这种二叉树能大幅度提高搜索效率。
如果一个二叉树满足：对于任意一个节点，其值不小于左子树的任何节点，
且不大于右子树的任何节点（反之亦可），则为二叉搜索树。如果按照中序遍历，其遍历结果是一个有序序列。
因此，二叉搜索树又称为二叉排序树。不同于最大堆（或最小堆），
其只要求当前节点与当前节点的左右子节点满足一定关系。
下面以非降序二叉搜索树为例。

 * A simple binary search tree
 *           6                  6
 *          / \                / \
 *         /   \              /   \
 *        3     8            3     8
 *       /     / \          /     / \
 *      /     /   \        /     /   \
 *     2     7     9      2     4*    9
 *
 *       (A) BST             (B) 非 BST， 因为根节点6大于右子树中的节点4。

*/

#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

class BSTNode  // 二叉搜索树节点
{
public:
    int Key;
    BSTNode * Left; // 左子节点 指针
    BSTNode * Right;// 右子节点 指针
    BSTNode * Parent; // 比普通的二叉树多一个父节点指针
                      // 因为要 通过左子节点 访问 父节点，方便遍历 二叉搜索树
    int Height;//当前子树的高度??
};

class BST // 二叉搜索树
{
private:
    BSTNode * root; // 树根节点

protected: // 保护类型，可继承==
    BSTNode * Insert(BSTNode * node, int key);
      // 树中插入一个节点，若为第一次，则设置为根节点，之后根据大小 递归放入左/右子树中的合适位置
    void PrintTreeInOrder(BSTNode * node); // 按 序列 递归打印 二叉搜索树 各个节点信息 
    BSTNode * Search(BSTNode * node, int key); // 搜索一个节点，节点值比给定值大，在左子树递归查找，反之在右子树递归查找
    int FindMin(BSTNode * node);// 最小值，一个BST的最左叶子节点的key值就是BST所有key值中最小的,不停递归左子树，直到无左子树时。
    int FindMax(BSTNode * node);// 最大值，一个BST的最右叶子节点的key值就是BST所有key值中最大的,不停递归右子树，直到无右子树时。
    int Successor(BSTNode * node);// x的SUCCESSOR满足x.key<=x.SUCCESSOR.key,并且x.SUCCESSOR.key是距离x.key最近的值，
                                  // 即x.SUCCESSOR.key是x.key的最小上限（minimum ceiling）
                                  // 在右子树/左父亲 中 递归 寻找最小的
    int Predecessor(BSTNode * node);// 最大下限==
                                    // 在左子树/右父亲 递归 寻找最大的
    
    BSTNode * Remove(BSTNode * node, int v); // 删除节点

public:
    BST();
    
    // 外部可访问==============
    void Insert(int key);
    void PrintTreeInOrder();
    bool Search(int key);
    int FindMin();
    int FindMax();
    int Successor(int key);
    int Predecessor(int key);
    void Remove(int v);
};

#endif // BSTNODE_H
