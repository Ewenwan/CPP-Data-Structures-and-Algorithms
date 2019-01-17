// Project: Stack.cbp
// File   : Stack.h
#ifndef STACK_H
#define STACK_H

#include "../../Node/Node.h"

template <typename T> // 模板类型
class Stack
{
private:   // 私有数据
 int m_count;// 熟练
 Node<T> * m_top; // 栈顶指针
 
 
public: // 公开
 Stack();       // 类构造函数
 bool IsEmpty();// 空检查
 T Top();       // 获取栈顶元素
 void Push(T val);// 栈顶插入元素
 void Pop();      // 弹出栈顶元素
};

template <typename T>
Stack<T>::Stack() : m_count(0), m_top(NULL) {}

// 空检查===============
template <typename T>
bool Stack<T>::IsEmpty()
{
 // return TRUE if there are no items
 // otherwise, return FALSE
 return m_count <= 0;
}

// 获取栈顶元素=======
template <typename T>
T Stack<T>::Top()
{
 // Just return the value of m_top node
 return m_top->Value;
}

// 栈顶插入元素===========
template <typename T>
void Stack<T>::Push(T val)
{
 // 创建一个新节点
 Node<T> * node = new Node<T>(val);
 // 新节点的 后继 指向 原 栈顶节点
 node->Next = m_top;
 // 新节点 重置为 新栈顶节点
 m_top = node;
 // 数量++
 m_count++;
}

// 弹出栈顶元素===========
template <typename T>
void Stack<T>::Pop()
{
 // 空栈直接返回
 if(IsEmpty())
      return;
 // 旧栈顶节点，待删除
 Node<T> * node = m_top;
 // 旧栈顶节点的后继 设置为 新栈顶节点
 m_top = m_top->Next;
 // 删除原 旧栈顶节点
 delete node;
 // 数量--
 m_count--;
}

#endif // STACK_H
