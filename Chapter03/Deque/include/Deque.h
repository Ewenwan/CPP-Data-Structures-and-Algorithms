// Project: Deque.cbp
// File   : Deque.h 双端队列 Double Queue 可以从两端进行插入和删除操作 双向节点构成
#ifndef DEQUE_H
#define DEQUE_H

#include "../../Node/DoublyNode.h"

template <typename T>
class Deque
{
private:
    int m_count; // 数量
    DoublyNode<T> * m_front;// 队首节点指针  双向节点
    DoublyNode<T> * m_back; // 队尾节点指针

public:
    Deque();
    bool IsEmpty();
    T Front();
    T Back();
    void EnqueueFront(T val); // 队首插入元素 新节点后继指向原队首，原队首前继指向新节点，新节点作为新队首  
    void EnqueueBack(T val);  // 队尾插入元素 原队尾后继指向新节点  新节点前继指向原队尾，新节点作为新队尾
    void DequeueFront();      // 队首删除元素 保存旧队首，旧队首后继作为新队首，新队首前继指向NULL，删除旧队首
    void DequeueBack();       // 队尾删除元素 保存旧队尾，旧队尾前继作为新队尾，新队尾后继指向NULL，删除旧队尾
};

template <typename T>
Deque<T>::Deque() : m_count(0), m_front(NULL), m_back(NULL) {}

template <typename T>
bool Deque<T>::IsEmpty()
{
    // return TRUE if there's at least one item
    // otherwise, return FALSE
    return m_count <= 0;
}

template <typename T>
T Deque<T>::Front()
{
    // Just return the value
    // of m_front node
    return m_front->Value;
}

template <typename T>
T Deque<T>::Back()
{
    // Just return the value
    // of m_back node
    return m_back->Value;
}

template <typename T>
void Deque<T>::EnqueueFront(T val)
{
    // Create a new Node
    DoublyNode<T> * node = new DoublyNode<T>(val);

    // The current m_front will no longer become a m_front
    // so the Next pointer of the new Node will
    // point to the current m_front
    node->Next = m_front;

    // If the current m_front is exist,
    // the previous pointer of the current m_front
    // should point to the node
    if(m_front != NULL)
        m_front->Previous = node;

    // The new Node now become the m_front
    m_front = node;

    // If the deque is empty
    // The m_back is also the m_front
    if(m_count == 0)
        m_back = m_front;

    // One element is added
    m_count++;
}

template <typename T>
void Deque<T>::EnqueueBack(T val)
{
    // If the deque is empty,
    // just simply invoke EnqueueFront()
    if(m_count == 0)
    {
        EnqueueFront(val);
        return;
    }

    // Create a new Node
    DoublyNode<T> * node = new DoublyNode<T>(val);

    // The current m_back will no longer become a m_back
    // so the Next pointer of the current m_back will
    // point to the new node
    m_back->Next = node;

    // Also, the previous pointer of the new node
    // should point to the current m_back
    node->Previous = m_back;

    // The new Node now become the m_back
    m_back = node;

    // One element is added
    m_count++;
}

template <typename T>
void Deque<T>::DequeueFront()
{
    // Do nothing if deque is empty
    if(m_count == 0)
        return;

    // Save the current m_front
    // to a new node
    DoublyNode<T> * node = m_front;

    // Point the m_front Pointer
    // to the element next to the current m_front
    m_front = m_front->Next;

    // Now it's safe to remove
    // the first element
    delete node;

    // If there's still any element in the deque,
    // the previous pointer of the m_front
    // should point to NULL
    if(m_front != NULL)
        m_front->Previous = NULL;

    // One element is removed
    m_count--;
}

template <typename T>
void Deque<T>::DequeueBack()
{
    // Do nothing if deque is empty
    if(m_count == 0)
        return;

    // If deque element is only one
    // just simply call DequeueFront()
    if(m_count == 1)
    {
        DequeueFront();
        return;
    }

    // Save the current m_back
    // to a new node
    DoublyNode<T> * node = m_back;

    // Point the m_back Pointer
    // to the element before the current m_back
    m_back = m_back->Previous;

    // Set the new Next pointer of the new m_back
    // to NULL since we are going to delete
    // the last element
    m_back->Next = NULL;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    m_count--;
}

#endif // DEQUE_H
