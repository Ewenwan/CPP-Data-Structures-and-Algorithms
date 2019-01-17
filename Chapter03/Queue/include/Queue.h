// Project: Queue.cbp
// File   : Queue.h
//一种只能从一端插入元素，从另一端删除元素的 容器
// First In First Out(FIFO) 先入先出 队列
///现实世界中的 排队，打印机队列...都是队列的实例
#ifndef QUEUE_H
#define QUEUE_H

#include "../../Node/Node.h"

template <typename T>
class Queue
{
private:
    int m_count; // 节点数量
    Node<T> * m_front; // 前端节点(队首) 指针 删除元素入口
    Node<T> * m_back;  // 后端节点(队尾) 指针 插入元素入口

public:
    Queue();// 构造函数
    bool IsEmpty();// 为空检查
    T Front();     // 获取 队首 元素
    void Enqueue(T val); // 从队尾 插入元素
    void Dequeue();      // 从队首 删除元素
};

template <typename T>
Queue<T>::Queue() : m_count(0), m_front(NULL), m_back(NULL) {}

template <typename T>
bool Queue<T>::IsEmpty()
{
    // return TRUE if there's at least one item
    // otherwise, return FALSE
    return m_count <= 0;
}

template <typename T>
T Queue<T>::Front()
{
    // Just return the value
    // of m_front node
    return m_front->Value;
}

template <typename T>
void Queue<T>::Enqueue(T val)
{
    // Create a new Node
    Node<T> * node = new Node<T>(val);

    if(m_count == 0)
    {
        // If the queue is empty
        // the new node will be
        // m_front and m_back
        node->Next = NULL;
        m_front = node;
        m_back = m_front;
    }
    else
    {
        // If there's at least one element
        // in the queue, the current m_back element
        // won't be the Back element anymore
        // so the Next pointer of the current m_back
        // point to the new node
        m_back->Next = node;

        // The new Node now become the Back position
        m_back = node;
    }

    // One element is added
    m_count++;
}

template <typename T>
void Queue<T>::Dequeue()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // Save the current Front
    // to a new node
    Node<T> * node = m_front;

    // Point the Front pointer
    // to the element next to the current Front
    m_front = m_front->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // One element is removed
    m_count--;
}

#endif // QUEUE_H
