// Project: Node_Chain.cbp
// File   : main.cpp 节点链，关系网，朋友圈网，人脉圈，七大姑八大姨...
#include <iostream>

using namespace std;

class Node // 节点类，嫌疑人
{
public:
    int Value;      // 嫌疑人信息，数据值，
    Node * Next;    // 节点指向信息，人物关系
};

// 根据任务链信息，找出整个犯罪团伙===============
void PrintNode(Node * node)
{
    // NULL 表明 线索到头了，幕后大佬后面没老虎了===
    while(node != NULL)
    {
        cout << node->Value << " -> ";// 打印当前节点(嫌疑人)的信息(名字，脏污，财产)
        node = node->Next;            // 找到下一个嫌疑人=====
    }

    cout << "NULL" << endl;
}

int main()
{
    // +------+------+
    // |  7   | NULL |
    // +------+------+
    // 节点1
    Node * node1 = new Node;
    node1->Value = 7;

    // +------+------+
    // |  14  | NULL |
    // +------+------+
    // 节点2
    Node * node2 = new Node;
    node2->Value = 14;

    // +------+------+
    // |  21  | NULL |
    // +------+------+
    // 节点3
    Node * node3 = new Node;
    node3->Value = 21;

    // +------+------+  +------+------+  +------+------+
    // |  7   |   +---->|  14  | NULL |  |  21  | NULL |
    // +------+------+  +------+------+  +------+------+
    // 节点1--->节点2
    node1->Next = node2;

    // +------+------+  +------+------+  +------+------+
    // |  7   |   +---->|  14  |   +---->|  21  | NULL |
    // +------+------+  +------+------+  +------+------+
    // 节点1--->节点2--->节点3
    node2->Next = node3;

    // 打印 节点链，找出人脉链，挖地三尺
    PrintNode(node1);

    return 0;
}
