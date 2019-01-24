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

/*  A simple binary search tree
 *           6                  6
 *          / \                / \
 *         /   \              /   \
 *        3     8            3     8
 *       /     / \          /     / \
 *      /     /   \        /     /   \
 *     2     7     9      2     4*    9
 *
 *       (A) BST             (B) 非 BST， 因为根节点6大于右子树中的节点4。
 * */
*/

#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

class BSTNode
{
public:
    int Key;
    BSTNode * Left;
    BSTNode * Right;
    BSTNode * Parent;
    int Height;
};

class BST
{
private:
    BSTNode * root;

protected:
    BSTNode * Insert(BSTNode * node, int key);
    void PrintTreeInOrder(BSTNode * node);
    BSTNode * Search(BSTNode * node, int key);
    int FindMin(BSTNode * node);
    int FindMax(BSTNode * node);
    int Successor(BSTNode * node);
    int Predecessor(BSTNode * node);
    BSTNode * Remove(BSTNode * node, int v);

public:
    BST();

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
