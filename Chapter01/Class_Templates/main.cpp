// 15. 类模板 Class templates  类模板=内置类型可以传入类类型=
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
    // 虚函数 相当于先占坑，先占茅坑======
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

    // Copy assignment operator overloading
    void operator = (const Dog &D)
    {
         m_name = D.m_name;
    }

    // here we implement the interface
    string MakeSound() override
    {
        return "woof-woof!";
    }

};

class Cat : public Animal
{
public:
    // Forward the constructor arguments
    Cat(string name) : Animal(name) {}

    // Copy assignment operator overloading
    void operator = (const Cat &D)
    {
         m_name = D.m_name;
    }

    // here we implement the interface
    string MakeSound() override
    {
        return "meow-meow!";
    }

};
// 函数模板，接收一个类对象============
template<typename T>
void GetNameAndMakeSound(T& theAnimal)
{
    cout << theAnimal.GetName() << " goes ";
    cout << theAnimal.MakeSound() << endl;
}

// 类模板====内置类型 可以传入 类类型=================
template <typename T> // 类内 变量的类型 为 模板
class AnimalTemplate  // 类 名字
{
private:
    T m_animal; // 模板类型 变量=== 可以直接传入类类型===

public:
    AnimalTemplate(T animal) : m_animal(animal) {}
    
    // 打印 信息
    void GetNameAndMakeSound()
    {
        cout << m_animal.GetName() << " goes ";
        cout << m_animal.MakeSound() << endl;
    }
};

int main()
{
    // 类实例 Dog
    Dog dog = Dog("Bulldog");
    // 传入 Dog类对象实例 构造 模板类实例====
    AnimalTemplate<Dog> dogTemplate(dog);
    dogTemplate.GetNameAndMakeSound();
    
    // 
    Cat cat = Cat("Persian Cat");
    AnimalTemplate<Cat> catTemplate(cat);
    catTemplate.GetNameAndMakeSound();

    return 0;
}
