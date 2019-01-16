// Project: Singly_Linked_List.cbp
// File   : Node.h 链表中的 单一节点实现，模板节点，可存储许多类型数据
#ifndef NODE_H
#define NODE_H

#include <iostream>

// 模板节点，可存储许多类型数据
template <typename T>
class Node
{
public:
    T Value;
    Node<T> * Next;
    // 类 构造函数 声明
    Node(T value);
};

// 类构造函数实现
// 拿到外面的话，就需要在函数前面添加 Node<T>:: 类名属性
template <typename T>
Node<T>::Node(T value) : Value(value), Next(NULL) {}

#endif // NODE_H
