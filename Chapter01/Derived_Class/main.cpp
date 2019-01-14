// 12. 创建类的继承者，父类虚函数占坑，之类实现具体函数，基因遗传，豌豆杂交
#include <iostream>

using namespace std;

class Animal // 动物类
{
private:
    string m_name;

public:
    // 构造函数
    Animal(string name) : m_name(name)
    {
    }
    
    // 不同的动物有不同的叫声，该动物大类下 设置一个虚函数 相当于先占坑，先占茅坑
    // The interface that has to be implemented in derived class
    // 等到继承者在实现，注意该函数前面 有 virtual 符号
    virtual string MakeSound() = 0;

    string GetName()
    {
        return m_name;
    }
};

class Dog : public Animal // 小狗类Dog 公开 继承于 父类 Animal 动物
{
public:
    // Forward the constructor arguments 转发构造函数参数？
    Dog(string name) : Animal(name) {}// 直接使用 父类的 构造函数

    // 在之类中实现具体的叫声函数(父类中定义的虚函数，占的茅坑)
    string MakeSound() override
    {
        return "woof-woof!";// 旺旺雪饼好吃======
    }

};

int main()
{   
    // 直接创建 之类的对象
    Dog dog = Dog("Bulldog");

    cout << dog.GetName() << " is barking: ";// 该函数是父类中的实现
    cout << dog.MakeSound() << endl;         // 该函数是之类中的实现

    return 0;
}
