// Project: List.cbp
// File   : List.cpp 动态内存的数组---列表实现=======
#include "List.h"

// 类构造函数，初始化函数，私有参数 元素数量 赋值为0
List::List(): m_count(0) {}

// 类 析构函数 
List::~List()
{
    delete[] m_items; // 清空内存占用
    m_items = NULL;   // 首地址指针 恢复为 NULL, 把猫灭口，避免乱跳
}

// 获取指定索引处的值======
int List::Get(int index)
{
    // 索引范围检查===
    if(index < 0 || index > m_count)
        return -1;
    return m_items[index];
}

// 在数组中插入一个元素，这里简单为创建一个新长度的数组，旧数组元素复制过来==
// 不过可以使用金蝉脱壳，每次多申请一些内存空间，容量不够了，再扩容=========
void List::Insert(int index, int val)
{
    // 索引范围检查===
    if(index < 0 || index > m_count)
        return;

    // 记录 旧数组首地址
    int * oldArray = m_items;

    // 插入一个元素，数组元素数量+1
    m_count++;

    // 每次都 新分配一个 新数组
    m_items = new int[m_count];

    // Fill the new array with inserted data
    for(int i=0, j=0; i < m_count; ++i)// i为 新数组索引，j为 旧数组索引
    {
        if(index == i)
        {
            m_items[i] = val; // 新插入的元素 放入指定 index 位置
        }
        else
        {
            m_items[i] = oldArray[j]; // 就数组元素 放到新数组中
            ++j; // 旧数组索引 ++ 
        }
    }

    // 清空 旧数组 内存空间
    delete [] oldArray;
}

// 在 列表中查找 指定元素
int List::Search(int val)
{
    // Looping through the array elements
    // return the array index if value is found
    for(int i=0; i < m_count; ++i)
    {
        if(m_items[i] == val)
        {
            return i; // 返回对应元素 的 索引
        }
    }

    return -1;// 没找到 返回 -1
}

// 删除指定索引处的元素，和插入的思想一致，创建一个新数组，除指定元素外不复制
void List::Remove(int index)
{
    // 索引范围检查===
    if(index < 0 || index > m_count)
        return;

   // 记录 旧数组首地址
    int * oldArray = m_items;

    // 删除一个元素，数量-1
    m_count--;

    // 初始化一个长度 较少1 的新数组
    m_items = new int[m_count];

    // 从旧数组 赋值 元素到新数组，除指定元素外不复制
    for(int i=0, j=0; i < m_count; ++i, ++j)//i 新数组索引，j旧数组索引
    {
        if(index == j)// 遍历到 旧数组中 指定 的 索引
        {
            ++j; // 直接跳过该 位置
        }

        m_items[i] = oldArray[j];// 旧数组元素 赋值 到 新数组元素
    }

    // 清空 旧数组 内存空间
    delete [] oldArray;
}

// 直接返回 内部私有数据 数量记录
int List::Count()
{
    return m_count;
}
