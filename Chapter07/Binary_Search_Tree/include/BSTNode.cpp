// Project: Binary_Search_Tree.cbp
// File   : BSTNode.cpp 二叉搜索树，左子树<=父节点<=右子树，使用递归结构来实现插入搜索删除等行为

#include "BSTNode.h"

// 类构造函数，根节点指针初始化为 空指针NULL
BST::BST() : root(NULL)
{
}

BSTNode * BST::Insert(BSTNode * node, int key)
{
    // 树中插入一个节点，若为第一次，则设置为根节点
    if(node == NULL)// 树节点指针为NULL，还没有节点
    {
        node = new BSTNode;// 新建一个节点
        node->Key = key;   // 更新 节点值
        node->Left = NULL; // 左/右/父 节点指针 为 NULL
        node->Right = NULL;
        node->Parent = NULL;
    }
    // 树中已有节点，给定值比 根节点值大，在右子树中插入
    else if(node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }
    // 给定值 比 根节点值小，在左子树中插入
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    return node;
}

void BST::Insert(int key)
{
    // Invoking Insert() function
    // and passing root node and given key
    root = Insert(root, key);
}

void BST::PrintTreeInOrder(BSTNode * node)
{
    // Stop printing if no node found
    if(node == NULL)
        return;

    //打印左子树
    PrintTreeInOrder(node->Left);

    // 打印当前节点值
    std::cout << node->Key << " ";

    // 打印右子树
    PrintTreeInOrder(node->Right);
}

void BST::PrintTreeInOrder()
{
    // Traverse the BST
    // from root node
    // then print all keys
    PrintTreeInOrder(root);
    std::cout << std::endl;
}

// 搜索一个节点，节点值比给定值大，在左子树递归查找，反之在右子树递归查找
BSTNode * BST::Search(BSTNode * node, int key)
{
    // 树非空，递归结束条件
    if (node == NULL)
        return NULL;
    // 节点值 正好等于 查找值
    else if(node->Key == key)
        return node;
    // 给定值大，在右子树中查找
    else if(node->Key < key)
        return Search(node->Right, key);
    // 给定值小在 左子树中查找
    else
        return Search(node->Left, key);
}

bool BST::Search(int key)
{
    // Invoking Search() operation
    // and passing root node
    BSTNode * result = Search(root, key);

    // If key is found, returns TRUE
    // otherwise returns FALSE
    return result == NULL ?
        false :
        true;
}

// 一个BST的最左叶子节点的key值就是BST所有key值中最小的。
int BST::FindMin(BSTNode * node)
{
    if(node == NULL)
        return -1;
    // 无左子节点了，该节点就是最小值
    else if(node->Left == NULL)
        return node->Key;
    // 在 左子树中递归左子树
    else
        return FindMin(node->Left);
}

int BST::FindMin()
{
    return FindMin(root);
}

// 一个BST的最右叶子节点的key值就是BST所有key值中最大的。
int BST::FindMax(BSTNode * node)
{
    if(node == NULL)
        return -1;
    // 无右子节点了，该节点就是最大值
    else if(node->Right == NULL)
        return node->Key;
    else
    // 在 右子树中递归右子树
        return FindMax(node->Right);
}

int BST::FindMax()
{
    return FindMax(root);
}

// 指定节点的最小上限（minimum ceiling）： 在右子树中寻找最小值 / 递归 父节点
int BST::Successor(BSTNode * node)
{
    // 递归找右子树中的最小值
    if (node->Right != NULL)
    {
        return FindMin(node->Right); // 右子树 中的 最左子节点为最小值
    }
    // 查看父节点中的
    else
    {// 如果x不存在右孩子，则检查x是否有父亲节点并且x必须是父亲节点的左孩子
        BSTNode * parentNode = node->Parent; // 父节点
        BSTNode * currentNode = node;        // 当前节点

        // If currentNode is not root and
        // currentNode is its right children
        // continue moving up
        while ((parentNode != NULL) &&
            (currentNode == parentNode->Right))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // If parentNode is not NULL
        // then the key of parentNode is
        // the successor of node
        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

int BST::Successor(int key)
{
    // Search the key's node first
    BSTNode * keyNode = Search(root, key);

    // Return the key.
    // If the key is not found or
    // successor is not found,
    // return -1
    return keyNode == NULL ?
        -1 :
        Successor(keyNode);
}

//最大下限
int BST::Predecessor(BSTNode * node)
{
    // The predecessor is the maximum key value
    // of left subtree
    if (node->Left != NULL)
    {
        return FindMax(node->Left);
    }
    // If no any left subtree
    else
    {
        BSTNode * parentNode = node->Parent;
        BSTNode * currentNode = node;

        // If currentNode is not root and
        // currentNode is its left children
        // continue moving up
        while ((parentNode != NULL) &&
            (currentNode == parentNode->Left))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        // If parentNode is not NULL
        // then the key of parentNode is
        // the predecessor of node
        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

int BST::Predecessor(int key)
{
    // Search the key's node first
    BSTNode * keyNode = Search(root, key);

    // Return the key.
    // If the key is not found or
    // predecessor is not found,
    // return -1
    return keyNode == NULL ?
        -1 :
        Predecessor(keyNode);
}

BSTNode * BST::Remove(
    BSTNode * node,
    int key)
{
    // The given node is
    // not found in BST
    if (node == NULL)
        return NULL;

    // Target node is found
    if (node->Key == key)
    {
        // If the node is a leaf node
        // The node can be safely removed
        if (node->Left == NULL && node->Right == NULL)
            node = NULL;
        // The node have only one child at right
        else if (node->Left == NULL && node->Right != NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Right->Parent = node->Parent;

            // Bypass node
            node = node->Right;
        }
        // The node have only one child at left
        else if (node->Left != NULL && node->Right == NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->Left->Parent = node->Parent;

            // Bypass node
            node = node->Left;
        }
        // The node have two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            int successorKey = Successor(key);

            // Replace node's key with successor's key
            node->Key = successorKey;

            // Delete the old successor's key
            node->Right = Remove(node->Right, successorKey);
        }
    }
    // Target node's key is smaller than
    // the given key then search to right
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    // Target node's key is greater than
    // the given key then search to left
    else
        node->Left = Remove(node->Left, key);

    // Return the updated BST
    return node;
}

void BST::Remove(int key)
{
    root = Remove(root, key);
}



