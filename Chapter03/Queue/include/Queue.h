// Project: Queue.cbp
// File   : Queue.h
//一种只能从一端插入元素，从另一端删除元素的 容器
// First In First Out(FIFO) 先入先出 队列
//  现实世界中的 排队，打印机队列...都是队列的实例  队首----->...---->首尾--->新节点
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

// 构造函数====
template <typename T>
Queue<T>::Queue() : m_count(0), m_front(NULL), m_back(NULL) {}

template <typename T>
bool Queue<T>::IsEmpty()
{
    // 为空? 节点数量<=0
    return m_count <= 0;
}

template <typename T>
T Queue<T>::Front()
{
    // 队首节点 元素
    return m_front->Value;
}

// 队尾插入元素
template <typename T>
void Queue<T>::Enqueue(T val)
{
    // 新建一个节点
    Node<T> * node = new Node<T>(val);

    if(m_count == 0)
    {
        // 为空时，新建的一个节点 即为队首也为队尾节点===
        node->Next = NULL;
        m_front = node;
        m_back = m_front;
    }
    else
    {
        // 队首----->...---->首尾--->新节点
        m_back->Next = node;
        // 新节点变成 新 队尾
        m_back = node;
    }

    // 数量++
    m_count++;
}

// 队首删除元素
template <typename T>
void Queue<T>::Dequeue()
{
    // 空
    if(m_count == 0)
        return;

    // 原队首节点
    Node<T> * node = m_front;
    // 原队首节点的后继 设置为 新队首
    m_front = m_front->Next;
    // 删除 原队首节点
    delete node;

    // 数量--
    m_count--;
}

#endif // QUEUE_H
