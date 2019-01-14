// 13. 类的拷贝操作符重载实现，避免浅拷贝(shallow copying)问题
#include <iostream>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(string name) : m_name(name)
    {

    }
    // 父类虚函数 占坑===============
    virtual string MakeSound() = 0;

    string GetName()
    {
        return m_name;
    }

};

class Dog : public Animal // 之类Dog 公开继承 父类 Animal
{
public:
    // Forward the constructor arguments
    Dog(string name) : Animal(name) {} // 直接使用父类的构造函数

    // 拷贝赋值运算符重载 实现====
    void operator = (const Dog &D ) {
         m_name = D.m_name;// 赋值名字
      }

    // C++ 11添加了两个继承控制关键字：override和final===========================
    // override确保在派生类中声明的重载函数跟基类的虚函数有相同的签名。
    // final阻止类的进一步派生和虚函数的进一步重载。 
    string MakeSound() override
    {
        return "woof-woof!";
    }

};

int main()
{
    // 创建类实例对象========================
    Dog dog = Dog("Bulldog");
    cout << dog.GetName() << " is barking: ";
    cout << dog.MakeSound() << endl;
    
    // 直接拷贝类=============================
    Dog dog2 = dog;
    cout << dog2.GetName() << " is barking: ";
    cout << dog2.MakeSound() << endl;

    return 0;
}
