// 10. 一个简单的类实现 给 动物Animal 起名字
#include <iostream>

using namespace std;

class Animal // 定义一个 Animal 类
{
private:
    // 私有变量，可以被 类自己、类的朋友(同辈) 访问
    // main 函数等其他外部函数不可访问，但是可以通过 公开的函数间接访问
    string m_name;

public:
    // 给动物起名字
    void GiveName(string name)
    {
        m_name = name;
    }
    
    // 获取该宠物的名字
    // 外 部可以 通过 公开的函数间接访问 类内的私有变量=====
    string GetName()
    {
        return m_name;
    }
};

int main()
{
    // 定义一个 动物类 实例 小狗
    Animal dog = Animal();
    // 该小狗对象 起名字为 "dog"
    dog.GiveName("dog");
    // 打印该小狗的名字
    cout << "Hi, I'm a " << dog.GetName() << endl;

    return 0;
}
