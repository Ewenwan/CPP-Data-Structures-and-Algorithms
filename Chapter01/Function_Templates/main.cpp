// 14. 函数模板 Function templates 接收一个类对象 模板为参数
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
    // 父类虚函数占坑===================
    virtual string MakeSound() = 0;

    string GetName()
    {
        return m_name;
    }

};

class Dog : public Animal
{
public:
    // Forward the constructor arguments
    Dog(string name) : Animal(name) {}

    // 拷贝运算符重载======
    void operator = (const Dog &D)
    {
         m_name = D.m_name;
    }

    // 虚函数实现
    string MakeSound() override
    {
        return "woof-woof!";
    }

};

class Cat : public Animal // 公开继承 父类 Animal
{
public:
    // 调用父类的构造函数
    Cat(string name) : Animal(name) {}

    // 拷贝运算符重载======
    void operator = (const Cat &D)
    {
         m_name = D.m_name;
    }

    // here we implement the interface
    string MakeSound() override
    {
        return "meow-meow!"; // 与 dog 叫声不一样====
    }

};

// 函数模板，接收一个类对象============
template<typename T> // 注意关键字 template<typename *>===== 
void GetNameAndMakeSound(T& theAnimal)
{
    cout << theAnimal.GetName() << " goes ";
    cout << theAnimal.MakeSound() << endl;
}

int main()
{
    Dog dog = Dog("Bulldog");
    GetNameAndMakeSound(dog);

    Cat cat = Cat("Persian Cat");
    GetNameAndMakeSound(cat);

    return 0;
}
