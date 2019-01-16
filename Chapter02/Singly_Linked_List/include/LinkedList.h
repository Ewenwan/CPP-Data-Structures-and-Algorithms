// Project: Singly_Linked_List.cbp
// File   : LinkedList.h   链表实现，比 节点链 多一些功能，插入/删除节点==
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"   // 单个模板节点

// 模板链表==================
template <typename T>
class LinkedList
{
private:
    int m_count; // 实际节点数量

public:
    // 保存了聊表的首尾信息，方便管理
    // The first node in the list or null if empty
    Node<T> * Head; // 链表表头节点
    // The last node in the list or null if empty
    Node<T> * Tail; // 链表表尾节点

    // 类构造函数 Constructor
    LinkedList();

    // 获取第 index 个 节点 Get() operation
    Node<T> * Get(int index);

    // 在链表中 插入节点 的操作===Insert() operation
    void InsertHead(T val);// 头部插入节点
    void InsertTail(T val);// 尾部插入节点
    void Insert(int index, T val);// 插入节点

    // 在链表中查找指定的值 Search() operation
    int Search(T val);

    // 删除节点的操作 ==Remove() operation===
    void RemoveHead();// 去除表头节点
    void RemoveTail();// 去除表尾节点
    void Remove(int index);// 去 链条中的节点

    // 附加操作======
    int Count();     // 节点数量 统计
    void PrintList();// 打印链表中的每一个节点的信息====
};

// 类 方法的实现方法 直接在 头文件中实现，比放在另一个cpp文件中好======

// 类构造函数，节点数量=0，首尾节点指针=NULL
template <typename T>
LinkedList<T>::LinkedList() : m_count(0), Head(NULL), Tail(NULL) {}

// 获取第 index 个节点
template <typename T>
Node<T> * LinkedList<T>::Get(int index)
{
    // 检查 索引 的合理性
    if(index < 0 || index > m_count)
        return NULL;

    // 从头结点开始 搜寻 
    Node<T> * node = Head;

    // 根据链表 链接信息搜索 到指定 号 人物
    for(int i = 0; i < index; ++i)
    {
        node = node->Next;
    }

    // Simply return the node result
    return node;
}

//=================================================
//     head             ...                tail
//index  0               1                  2
// +------+------+  +------+------+  +------+------+
// | 4.93 |   +---->| 6.45 |   +---->| 8.17 | NULL |
// +------+------+  +------+------+  +------+------+
//   前置节点            目标节点          后置节点
//   prevNode             node            nextNode
//   对目标索引位置 进行 插入/删除 操作时，先找到 目标节点及其前后位置的 前置节点 和 后置节点
//=================================================
// 头部插入节点=======================
template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    // 新建一个节点====
    Node<T> * node = new Node<T>(val);
    // 新节点的后继 指向原首节点 
    node->Next = Head;
    // 新节点重置为 首节点
    Head = node;

    // 仅有一个节点时，尾节点==首节点
    if(m_count == 0)
        Tail = Head;

    // One element is added
    m_count++;
}

// 尾部插入节点=======================
template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    // 链表为空时，和从头部插入节点一致===
    if(m_count == 0)
    {
        InsertHead(val);
        return;
    }
    
    // 新建一个节点
    Node<T> * node = new Node<T>(val);
    // 原链表的后继 设置为 新节点
    Tail->Next = node;
    // 新节点重置为 尾节点 
    Tail = node;

    // 数量++
    m_count++;
}

// 在指定位置处插入节点======================
template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
    // 检查位置index的合理性
    if(index < 0 || index > m_count)
        return;

    // 头部插入的情况====
    if(index == 0)
    {
        InsertHead(val);
        return;// 直接返回
    }
    // 尾部插入的情况====
    else if(index == m_count)
    {
        InsertTail(val);
        return;// 直接返回
    }

    // 链条中间插入 节点的情况===
    // 从首节点开始 遍历到 指定位置处的 前一个节点 (找到前置节点)
    Node<T> * prevNode = Head;
    // 找到 前置节点============  断开处的 前端
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // 指定位置的(后置节点)====  断开处的 后端
    Node<T> * nextNode = prevNode->Next;
    
    // 创建一个新节点===
    Node<T> * node = new Node<T>(val);
    // 新节点后继 指向 后置节点
    node->Next = nextNode;
    // 前置节点 后继 指向 新节点
    prevNode->Next = node;

    // 数量++
    m_count++;
}

// 遍历查找指定元素====================
template <typename T>
int LinkedList<T>::Search(T val)
{
    // 先看链表是否为空
    if(m_count == 0)
        return -1;

    // 指定元素的 index
    int index = 0;

    // 从头节点开始 遍历
    Node<T> * node = Head;

    // 开始遍历
    while(node->Value != val)
    {
        index++;
        node = node->Next;// 找到下一个节点
        // 遍历完全检查
        if(node == NULL)// 未到连表尾部
        {
            return -1;
        }
    }

    return index;
}

// 去除头部节点======================
template <typename T>
void LinkedList<T>::RemoveHead()
{
    // 链表 是否为空 检查
    if(m_count == 0)
        return;

    // 原 头部节点
    Node<T> * node = Head;
    // 原 头部节点的后继作为 新 首节点
    Head = Head->Next;
    // 删除原首节点
    delete node;
    
    // 仅有一个节点时，尾节点==首节点====
    if(m_count == 1)
        Tail = Head;//  新添加=========修复bug=====
    
    // 数量--
    m_count--;
}

// 去除尾部节点=========================
template <typename T>
void LinkedList<T>::RemoveTail()
{
    // 链表 是否为空 检查
    if(m_count == 0)
        return;

    // 当链表数量为1时，和去除头部节点一致
    if(m_count == 1)
    {
        RemoveHead();
        return;
    }

    // 从头节点开始，遍历到尾节点 的 前置节点，因为不能反向遍历，所以需要从头部向后遍历
    Node<T> * prevNode = Head;

    // 需要删除的节点
    Node<T> * node = Head->Next;

    // 遍历 找到指定的两个节点
    while(node->Next != NULL)// 注意是 需要删除的节点 的后继 不为 NULL
    {
        prevNode = prevNode->Next;// 前置节点
        node = node->Next;        // 需要删除的节点，即原 尾节点
    }

    // 原尾节点的 前置节点 需要 变成 新的 尾节点
    prevNode->Next = NULL; // 尾节点的后继 为 NULL
    Tail = prevNode;       // 前置节点 重置为  尾节点

    // 删除原 尾节点
    delete node;

    // 数量--
    m_count--;
}

// 删除指定索引位置的 节点
template <typename T>
void LinkedList<T>::Remove(int index)
{
    // 链表 是否为空 检查============
    if(m_count == 0)
        return;

    // 检查指定位置是否合理===========
    if(index < 0 || index >= m_count)
        return;

    // 删除头部的节点=============
    if(index == 0)
    {
        RemoveHead();
        return;// 直接返回 
    }
    //删除尾部的节点==============
    else if(index == m_count - 1)
    {
        RemoveTail();
        return;// 直接返回 
    }

    // 从 头部节点 开始 遍历
    Node<T> * prevNode = Head;

    // 找到指定 索引 前面的 前置节点
    for(int i = 0; i < index - 1; ++i)// 到index-2
    {
        prevNode = prevNode->Next;  // 前置节点 index-2 位置
    }

    // 指定节点
    Node<T> * node = prevNode->Next;// index-1 位置

    // 后置节点
    Node<T> * nextNode = node->Next;// index 位置 从0开始

    // 前置节点 的后继 设置为后置节点 跳过中间的 指定删除的节点
    prevNode->Next = nextNode;

    // 删除指定节点
    delete node;

    // 数量--
    m_count--;
}

// 链表节点数量记录========
template <typename T>
int LinkedList<T>::Count()
{
    return m_count;
}

// 打印整个链表============
template <typename T>
void LinkedList<T>::PrintList()
{
    Node<T> * node = Head;

    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }

    std::cout << "NULL" << std::endl;
}


#endif // LINKEDLIST_H
