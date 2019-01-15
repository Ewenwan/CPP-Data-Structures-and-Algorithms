// Project: List.cbp
// File   : List.h  列表=====
#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
    private:
        int m_count;
        int * m_items;

    public:
        List();
        ~List();
        // 获取指定索引处的值
        int Get(int index);
        // 在 指定索引 位置 插入元素
        void Insert(int index, int val);
        // 在列表 中搜索指定元素 val
        int Search(int val);
        // 删除指定索引处的 元素
        void Remove(int index);
        // 统 计 列表  元素数量 
        int Count();
};
#endif // LIST_H
