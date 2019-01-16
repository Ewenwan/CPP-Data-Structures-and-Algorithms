// 节点链 人物关系链 模板Template 实现，可存储多种类型的数据
// File   : main.cpp
#include <iostream>

using namespace std;

template <typename T> // template <typename *> 模板数据类型，任意数据类型
class Node
{
public:
    T Value; // 模板类型数据
    Node<T> * Next; // 下一个节点 关系人物 模板类型节点
    
    // 类构造函数======初始化两个内部数据===
    Node(T value) : Value(value), Next(NULL) {}
};

// 打印函数也是用 模板类型=====
template<typename T>
void PrintNode(Node<T> * node)// 传入节点指针
{
    // NULL 表明 线索到头了，幕后大佬后面没老虎了===
    while(node != NULL)
    {
        cout << node->Value << " -> ";// 打印当前节点(嫌疑人)的信息(名字，脏污，财产)
        node = node->Next;            // 找到下一个嫌疑人=====
    }
    // 打印最后的 终止标志 NULL
    cout << "NULL" << endl;
}

int main()
{
    // +------+------+
    // | 4.93 | NULL |
    // +------+------+
    // 节点1 浮点类型数据
    Node<float> * node1 = new Node<float>(4.93);

    // +------+------+
    // | 6.45 | NULL |
    // +------+------+
    // 节点2
    Node<float> * node2 = new Node<float>(6.45);

    // +------+------+
    // | 8.17 | NULL |
    // +------+------+
    // 节点3
    Node<float> * node3 = new Node<float>(8.17);

    // +------+------+  +------+------+  +------+------+
    // | 4.93 |   +---->| 6.45 | NULL |  | 8.17 | NULL |
    // +------+------+  +------+------+  +------+------+
    node1->Next = node2;

    // +------+------+  +------+------+  +------+------+
    // | 4.93 |   +---->| 6.45 |   +---->| 8.17 | NULL |
    // +------+------+  +------+------+  +------+------+
    // 节点1--->节点2--->节点3--->终止NULL
    node2->Next = node3;

    // Print the node
    PrintNode(node1);

    return 0;
}
