// Project: Doubly_Linked_List.cbp
// File   : DoublyLinkedList.h 双向链表 有双向节点构成的 双向索引链条
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

// 表头插入节点
template <typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
    // 新建节点
    DoublyNode<T> * node = new DoublyNode<T>(val);

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

template <typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
    // If the linked list is empty,
    // just simply invoke InsertHead()
    if(m_count == 0)
    {
        InsertHead(val);
        return;
    }

    // Create a new Node
    DoublyNode<T> * node = new DoublyNode<T>(val);

    // The current Tail will no longer become a Tail
    // so the Next pointer of the current Tail will
    // point to the new node
    Tail->Next = node;

    // Also, the previous pointer of the new node
    // should point to the current Tail
    node->Previous = Tail;

    // The new Node now become the Tail
    Tail = node;

    // One element is added
    m_count++;
}

template <typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
    // Check if the index is out of bound
    if(index < 0 || index > m_count)
        return;

    // If inserting a new Head
    if(index == 0)
    {
        InsertHead(val);
        return;
    }
    // If inserting a new Tail
    else if(index == m_count)
    {
        InsertTail(val);
        return;
    }

    // Start to find previous node
    // from the Head
    DoublyNode<T> * prevNode = Head;

    // Traverse the elements until
    // the selected index is found
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // Create the next node which is
    // the element after previous node
    DoublyNode<T> * nextNode = prevNode->Next;

    // Create a new node
    DoublyNode<T> * node = new DoublyNode<T>(val);

    // Insert this new node between
    // the previous node and the next node
    node->Next = nextNode;
    node->Previous = prevNode;
    prevNode->Next = node;
    nextNode->Previous = node;

    // One element is added
    m_count++;
}

template <typename T>
int DoublyLinkedList<T>::Search(T val)
{
    // If LinkedList is empty,
    // just return NOT_FOUND
    if(m_count == 0)
        return -1;

    // Need to count the index
    int index = 0;

    // Traverse from the Head node
    DoublyNode<T> * node = Head;

    // Traverse until the selected value
    // is matched with the value
    // of the current position,
    while(node->Value != val)
    {
        index++;
        node = node->Next;

        // This will happen
        // if the selected value
        // is not found
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

    // Save the current Head
    // to a new node
    DoublyNode<T> * node = Head;

    // Point the Head Pointer
    // to the element next to the current Head
    Head = Head->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // If there's still any element in the list,
    // the previous pointer of the Head
    // should point to NULL
    if(Head != NULL)
        Head->Previous = NULL;

    // One element is removed
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

    // Save the current Tail
    // to a new node
    DoublyNode<T> * node = Tail;

    // Point the Tail Pointer
    // to the element before the current Tail
    Tail = Tail->Previous;

    // Set the new Next pointer of the new Tail
    // to NULL since we are going to delete
    // the last element
    Tail->Next = NULL;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
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

    // Start to traverse the list
    // from the Head
    DoublyNode<T> * prevNode = Head;

    // Find the element before
    // the selected index
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // The removed element is after
    // the prevNode
    DoublyNode<T> * node = prevNode->Next;

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    DoublyNode<T> * nextNode = node->Next;

    // Link the prevNode to nextNode
    prevNode->Next = nextNode;
    nextNode->Previous = prevNode;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
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
    DoublyNode<T> * node = Tail;

    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Previous;
    }

    std::cout << "NULL" << std::endl;
}

#endif // DOUBLYLINKEDLIST_H
