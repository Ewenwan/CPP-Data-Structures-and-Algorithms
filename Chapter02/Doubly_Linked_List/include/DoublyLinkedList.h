// Project: Doubly_Linked_List.cbp
// File   : DoublyLinkedList.h 双向链表 有双向节点构成的 双向索引链条 在插入/删除节点时需要考虑 设置前继和后继节点的指针
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "DoublyNode.h"

template <typename T>
class DoublyLinkedList
{
    private: // 私有数据
        int m_count;// 双向节点 数量记录

    public:
        // 双向链表头
        DoublyNode<T> * Head;

        // 双向链表尾
        DoublyNode<T> * Tail;

        // 构造函数===========
        DoublyLinkedList();

        // 获取指定索引上的双向节点 Get() operation
        DoublyNode<T> * Get(int index);

        // 双向链表插入操作 Insert() operation
        void InsertHead(T val);// 表头插入
        void InsertTail(T val);// 表尾插入
        void Insert(int index, T val);// 普通插入函数

        //查找数据信息 Search() operation
        int Search(T val);

        // 双向链表删除节点操作 Remove() operation
        void RemoveHead();
        void RemoveTail();
        void Remove(int index);

        // 附加操作 Additional operation
        int Count();       // 计数 
        void PrintList();  // 正向打印 双向链表
        void PrintListBackward();// 反向打印 双向链表
        // 从尾节点 依次找 前继节点 反向遍历链表==
};

// 构造函数=========== DoublyLinkedList<T>:: 前置 所有关系
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : m_count(0), Head(NULL), Tail(NULL) {}

template <typename T>
DoublyNode<T> * DoublyLinkedList<T>::Get(int index)
{
    // 指定位置索引 范围检查
    if(index < 0 || index > m_count)
        return NULL;

    // 从头结点开始遍历
    DoublyNode<T> * node = Head;

    // 遍历到指定 index处
    for(int i = 0; i < index; ++i)
    {
        node = node->Next; // 0,...,index-1
    }

    // Simply return the node result
    return node;
}

// 表头插入节点==================================
template <typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
    // 新建节点
    DoublyNode<T> * node = new DoublyNode<T>(val);
    
    // 连接处 互相指向===========each other======
    // 新节点的后继 指向原 链表表头
    node->Next = Head;
    // 如果原 头结点存在，则原头结点的 前继 需要指向 新节点(作为新表头)
    if(Head != NULL)
        Head->Previous = node;

    // 新节点 重置为 链表表头
    Head = node;

    // 如果链表中只有一个节点，那么 表尾 == 表头
    if(m_count == 0)
        Tail = Head;

    // One element is added
    m_count++;
}

// 表尾插入节点=============================
template <typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
    // 链表为空时，和表头插入一致
    if(m_count == 0)
    {
        InsertHead(val);
        return;
    }

    // 新建一个节点
    DoublyNode<T> * node = new DoublyNode<T>(val);
    // 原尾节点 的 后继 设置为 新节点  // 注意需要双向关联
    Tail->Next = node;
    // 新节点的 前继 设置为 原尾节点
    node->Previous = Tail;
    // 新节点 重置为 链表的 尾节点
    Tail = node;

    // 数量++
    m_count++;
}

template <typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
    // 插入位置 范围检查
    if(index < 0 || index > m_count)
        return;

    // 在头部插入====
    if(index == 0)
    {
        InsertHead(val);
        return;
    }
    // 在尾部插入=====
    else if(index == m_count)
    {
        InsertTail(val);
        return;
    }

    // 目标位置的 前置节点
    DoublyNode<T> * prevNode = Head;

    // 遍历到 前置节点
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next; // 0,...,index-2
    }

    // 后置节点 
    DoublyNode<T> * nextNode = prevNode->Next;//0,...,index-1

    // 创建一个新的节点
    DoublyNode<T> * node = new DoublyNode<T>(val);

    // 需要重新设置4个指向======
    // prevNode----> node ------>nextNode
    // prevNode<---- node <----- nextNode
    node->Next = nextNode;     // 1.               node ------>nextNode
    node->Previous = prevNode; // 2. prevNode<---- node
    prevNode->Next = node;     // 3. prevNode----> node
    nextNode->Previous = node; // 4.               node <----- nextNode

    // One element is added
    m_count++;
}

template <typename T>
int DoublyLinkedList<T>::Search(T val)
{
    // 链表为空
    if(m_count == 0)
        return -1;

    // 找到的位置
    int index = 0;

    // 从头结点开始遍历
    DoublyNode<T> * node = Head;

    // 找到指定值
    while(node->Value != val)
    {
        index++;
        node = node->Next;

        // 直到找到 链表尾部
        if(node == NULL)
        {
            return -1;
        }
    }

    return index;
}

template <typename T>
void DoublyLinkedList<T>::RemoveHead()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // 原 链表头
    DoublyNode<T> * node = Head;

    // 原 链表头后继 设置为 新链表头
    Head = Head->Next;

    // 删除原链表头
    delete node;

    // 设置 表头前置 节点为 NULL
    if(Head != NULL)
        Head->Previous = NULL;

    // 数量--
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::RemoveTail()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // If List element is only one
    // just simply call RemoveHead()
    if(m_count == 1)
    {
        RemoveHead();
        return;
    }

    // 原表尾节点
    DoublyNode<T> * node = Tail;

    // 可以反向遍历 找到 原表尾节点的 前置节点，并设置为 新的表尾节点
    Tail = Tail->Previous;

    // 表尾节点的后继设置为 NULL
    Tail->Next = NULL;

    // 删除原 链表表尾节点
    delete node;

    // 数量--
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::Remove(int index)
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Do nothing if index is out of bound
    if(index < 0 || index >= m_count)
        return;

    // If removing the current Head
    if(index == 0)
    {
        RemoveHead();
        return;
    }
    // If removing the current Tail
    else if(index == m_count - 1)
    {
        RemoveTail();
        return;
    }

    // 指定位置 的 前置节点
    DoublyNode<T> * prevNode = Head;
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next; // 0,...,index-2
    }
    // 需要删除的 目标节点
    DoublyNode<T> * node = prevNode->Next; // 0,...,index-1

    // 目标节点 后  的 后置节点
    DoublyNode<T> * nextNode = node->Next; // 0,...,index

    // 新增两个指向   前置节点 ---->  后置节点
    //               前置节点 <----  后置节点
    prevNode->Next = nextNode;     // 前置节点 ---->  后置节点
    nextNode->Previous = prevNode; // 前置节点 <----  后置节点

    // 删除目标节点
    delete node;

    // 数量--
    m_count--;
}

template <typename T>
int DoublyLinkedList<T>::Count()
{
    return m_count;
}

template <typename T>
void DoublyLinkedList<T>::PrintList()
{
    DoublyNode<T> * node = Head;

    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }

    std::cout << "NULL" << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::PrintListBackward()
{
    // 从尾节点 依次找 前继节点 反向遍历链表==
    DoublyNode<T> * node = Tail;

    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Previous;
    }

    std::cout << "NULL" << std::endl;
}

#endif // DOUBLYLINKEDLIST_H
