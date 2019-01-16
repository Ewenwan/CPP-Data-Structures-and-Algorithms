// Project: Doubly_Linked_List.cbp
// File   : DoublyNode.h 双向节点 带有 前继和后继 节点指针 模板数据类型
#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

#include <iostream>

// 双向节点 带有 前继和后继 节点指针
template <typename T>
class DoublyNode
{
// +----------+---------+---------+   
// Pre <------|  Value  | ---> Next
// +----------+---------+---------+  
    public:
        T Value; // 节点存储的信息，模板数据类型
        DoublyNode<T> * Previous; // 前继 节点指针
        DoublyNode<T> * Next;     // 后继 节点指针
        
        // 类对象 构造函数 声明
        DoublyNode(T value);      
};

// 类对象 构造函数 实现 
template <typename T>
DoublyNode<T>::DoublyNode(T value)
    // 值，前继和后继 节点指针 为NULL
    : Value(value), Previous(NULL), Next(NULL) {}

#endif // DOUBLYNODE_H
