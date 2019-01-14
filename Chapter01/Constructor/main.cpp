// 11. 类构造函数实现
#include <iostream>

using namespace std;

class Animal
{
private:
    string m_name;

public:
    // 类构造函数实现
    Animal(string name) : m_name(name)
    { // 使用传入变量 name 为 类内私有变量 m_name 赋值
      // 创建类实例式可传入对象的名字，省去了 命名函数
    }
    
    // 还是需要 通过公开的 方法 在外部 访问 类内变量
    string GetName()
    {
        return m_name;
    }
};

int main()
{
    // 创建类实例式可传入对象的名字，省去了 命名函数
    Animal dog = Animal("dog");
    // 还是需要 通过公开的 方法 在外部 访问 类内变量
    cout << "Hi, I'm a " << dog.GetName() << endl;

    return 0;
}
