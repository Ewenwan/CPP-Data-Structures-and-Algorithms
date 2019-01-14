# C++ Data Structures and Algorithms  数据结构和算法
This is the code repository for [C++ Data Structures and Algorithms](https://www.packtpub.com/application-development/c-data-structures-and-algorithms?utm_source=github&utm_medium=repository&utm_campaign=9781788835213), published by [Packt](https://www.packtpub.com/?utm_source=github). It contains all the supporting project files necessary to work through the book from start to finish.
## About the Book
C++ is a general-purpose programming language which has evolved over the years and is used to develop software for many different sectors. This book will be your companion as it takes you through implementing classic data structures and algorithms to help you get up and running as a confident C++ programmer.


## Instructions and Navigation
All of the code is organized into folders. Each folder starts with a number followed by the application name. For example, Chapter02.

All code files are present in their respective folder.

The code will look like the following:
```
// in_out.cpp
#include <iostream>
  int main ()
  {
     int i;
     std::cout << "Please enter an integer value: ";
     std::cin >> i;
     std::cout << "The value you entered is " << i;
     std::cout << "\n";
     return 0;
   }
// 编译 g++ in_out.cpp -o test
// 运行 ./test
```

To get through this book and successfully complete all the source code examples, you will
need the following specifications:
* Desktop PC or Notebook with Windows, Linux, or macOS
* GNU GCC v5.4.0 or above
* Code::Block IDE v17.12 (for Windows and Linux OS) or Code::Block IDE v13.12
(for macOS)

## Related Products
* [C++ High Performance](https://www.packtpub.com/application-development/c-high-performance?utm_source=github&utm_medium=repository&utm_campaign=9781787120952)

* [Mastering the C++17 STL](https://www.packtpub.com/application-development/mastering-c17-stl?utm_source=github&utm_medium=repository&utm_campaign=9781787126824)

* [Learning C++ Functional Programming](https://www.packtpub.com/application-development/learning-c-functional-programming?utm_source=github&utm_medium=repository&utm_campaign=9781787281974)

# 程序分析
## 章1 基础知识======================================
### 1.1 C++基础
#### 控制程序走向
> if else结构
```c
    int i =200;
    if(i > 100)
        cout << "greater than 100.";
    else
        cout << "equals or less than 100.";
```
> if elseif else 结构
```c
    int i =200;
    if(i > 100)
        cout << "greater than 100.";
    else if(i < 100)
        cout << "less than 100.";
    else
       
       cout << "equals to 100";
```
> 多if else分支
```c
    cin >> i;
    cin >> a;
    cin >> b;
    if(i == 1) // 谨记为 == 两个等号 判别是否相等
        cout << a << " + " << b << " is " << a + b;
    else if(i == 2)
        cout << a << " - " << b << " is " << a - b;
    else if(i == 3)
        cout << a << " * " << b << " is " << a * b;
    else if(i == 4)
        cout << a << " / " << b << " is " << a / b;
```
> switch case 结构
```c
    cin >> i;
    cin >> a;
    cin >> b;
    switch(i)
    {
    case 1: // 冒号
        cout << a << " + " << b << " is " << a + b;
        break; // break; 一般不省略
    case 2:
        cout << a << " - " << b << " is " << a - b;
        break;
    case 3:
        cout << a << " * " << b << " is " << a * b;
        break;
    case 4:
        cout << a << " / " << b << " is " << a / b;
        break;
    // default: break; 默认分支====
    }
```

> for循环
```c
// 产生随机数======
int GenerateRandomNumber(int min, int max)
{
    // static used for efficiency,
    // so we only calculate this value once
    // 静态数据，只计算一次，将随机数变成 0~1之间
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    // evenly distribute the random number
    // across our range
    // rand() * fraction) 为 0~1之间的数====
    return min + static_cast<int>(
        (max - min + 1) * (rand() * fraction));
}

// 设置随机数种子
srand(static_cast<unsigned int>(time(0)));
// loop ten times
for (int i=0; i < 10; ++i) // 循环10次
{
    cout << GenerateRandomNumber(0, 100) << " "; // 0~100之间
}
    
```

> while循环 猜数字
```c

// 计算机随机产生一个整数  1~100之间
int computerNumber = GenerateRandomNumber(1, 100);

// 用户 猜 的 数字
int userNumber;
cout << "Please enter a number between 1 to 100: ";
cin >> userNumber;

// 猜的不对，会一直循环
while(userNumber != computerNumber)
{
    cout << userNumber << " is ";
    if(userNumber > computerNumber)
        cout << "greater";
    else
        cout << "lower";
    cout << " than computer's number" << endl;
    cout << "Choose another number: ";
    cin >> userNumber;
}
```

>do while循环 计算机猜数字
```c
    char userChar; // l/L g/G Y/y
    int iMin = 1;  // 计算机猜的范围
    int iMax = 100;
    int iGuess     // 计算机猜的数字
    // Run the DO-WHILE loop
    do
    {
        iGuess = GenerateRandomNumber(iMin, iMax);// 根据不断缩小的范围，产生随机数
        cout << "I guess your number is " << iGuess << endl;
        cout << "What do you think? ";
        cin >> userChar; // l/L代表计算机产生的数小了
        if(userChar == 'L' || userChar == 'l')
            iMin = iGuess + 1;// 更新 搜索下限为上次猜的数+1
        else if(userChar == 'G' || userChar == 'g')// g/G代表计算机猜的数大了
            iMax = iGuess - 1;// 更新搜索上限
    }
    while(userChar != 'Y' && userChar != 'y'); // 计算机没猜对，会一直猜
```
#### 枚举变量 使用整数索引获取值 结构体混合变量
>
```c
// 牌的花色
// 黑桃（Spades)、红桃（Hearts)、草花（Clubs）、方块（Diamonds） 牌面（face）
enum CardSuits
{
    Club,
    Diamond,
    Heart,
    Spade
};
// 牌的大小
enum CardElements
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

// 根据枚举变量值，获取牌花色字符串========
string GetSuitString(CardSuits suit)
{
    string s;

    switch(suit)
    {
        case Club:
            s = "Club";
            break;
        case Diamond:
            s = "Diamond";
            break;
        case Heart:
            s = "Heart";
            break;
        case Spade:
            s = "Spade";
            break;
    }

    return s;
}

// 根据枚举变量值，获取牌面值字符串========
string GetElementString(CardElements element)
{
    string e;

    switch(element)
    {
        case Ace:
            e = "Ace";
            break;
        case Two:
            e = "Two";
            break;
        case Three:
            e = "Three";
            break;
        case Four:
            e = "Four";
            break;
        case Five:
            e = "Five";
            break;
        case Six:
            e = "Six";
            break;
        case Seven:
            e = "Seven";
            break;
        case Eight:
            e = "Eight";
            break;
        case Nine:
            e = "Nine";
            break;
        case Ten:
            e = "Ten";
            break;
        case Jack:
            e = "Jack";
            break;
        case Queen:
            e = "Queen";
            break;
        case King:
            e = "King";
            break;
    }

    return e;
}
// 描述牌信息 的 结构体======
struct Cards
{
 CardSuits suit;
 CardElements element;
};

// generate random suit and element card
int iSuit = GenerateRandomNumber(0, 3);    // 四种花色中的一种，下标
int iElement = GenerateRandomNumber(0, 12);// 13种面值大小中的一种，下标

// 根据下标索引 int 创建 枚举变量=========================
// https://www.cnblogs.com/chio/archive/2007/07/18/822389.html
// static_cast < type-id > ( expression )
// 把expression转换为type-id类型，但没有运行时类型检查来保证转换的安全性。
// 来源：为什么需要static_cast强制转换？
// 情况1：void指针 -> 其他类型指针,把void指针转换成目标类型的指针(不安全!!)
// 情况2：改变通常的标准转换,用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。
// 情况3：避免出现可能多种转换的歧义
CardSuits suit = static_cast<CardSuits>(
    iSuit);
CardElements element = static_cast<CardElements>(
    iElement);

// 结构体=====================
//Cards card;
//card.suit = static_cast<CardSuits>( GenerateRandomNumber(0, 3));
// card.element = static_cast<CardElements>(   GenerateRandomNumber(0, 12));

// 打印牌 的字符串信息===============
cout << "Your card is ";
cout << GetElementString(element);// card.element
cout << " of " << GetSuitString(suit) << endl;//card.suit
    
```

### 1.2 抽象数据结构 abstract data type class类实现
    一种包含 变量和方法的 容器 或者 集合
    成员数学：
        1. public 公开的，数据和方法可以被所有使用者访问
        2. protected 保护的，数据和方法，可以被 类自己、类的继承者(子代)、类的朋友(同辈) 访问
        3. private   私有的，数据和方法，可以被 类自己、类的朋友(同辈) 访问
    struct 默认为 public属性，推荐 使用struct定义 数据集合，不包括方法
    class  默认为 private属性

> 一个简单的类实现 给 动物Animal 起名字
```c
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

// 定义一个 动物类 实例 小狗
Animal dog = Animal();
// 该小狗对象 起名字为 "dog"
dog.GiveName("dog");
// 打印该小狗的名字
cout << "Hi, I'm a " << dog.GetName() << endl;
    
```

> 类构造函数实现
```c
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

// 创建类实例式可传入对象的名字，省去了 命名函数
Animal dog = Animal("dog");
// 还是需要 通过公开的 方法 在外部 访问 类内变量
cout << "Hi, I'm a " << dog.GetName() << endl;

```

> 创建类的继承者，父类虚函数占坑，子类实现具体函数，基因遗传，豌豆杂交
```c
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

    // 在子类中实现具体的叫声函数(父类中定义的虚函数，占的茅坑)
    string MakeSound() override  // 注意后面跟着的 override
    // C++ 11添加了两个继承控制关键字：override和final===========================
    // override确保在派生类中声明的重载函数跟基类的虚函数有相同的签名。
    // final阻止类的进一步派生和虚函数的进一步重载。 
    {
        return "woof-woof!";// 旺旺雪饼好吃======
    }

};

// 直接创建 之类的对象
Dog dog = Dog("Bulldog");

cout << dog.GetName() << " is barking: ";// 该函数是父类中的实现
cout << dog.MakeSound() << endl;         // 该函数是之类中的实现

```

> 类的拷贝操作符重载实现，避免浅拷贝(shallow copying)问题
```c
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

// 创建类实例对象========================
Dog dog = Dog("Bulldog");
cout << dog.GetName() << " is barking: ";
cout << dog.MakeSound() << endl;

// 直接拷贝类=============================
Dog dog2 = dog;
cout << dog2.GetName() << " is barking: ";
cout << dog2.MakeSound() << endl;
    
```
### 1.3  模板templates使用
> 函数模板 Function templates 接收一个类对象 模板为参数，打印同一类型 类对象的信息
```c
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
    cout << theAnimal.GetName() << " goes "; // 名字
    cout << theAnimal.MakeSound() << endl;   // 叫声
}

// 使用同一个模板函数，打印同一类型 类对象的信息======
Dog dog = Dog("Bulldog");
GetNameAndMakeSound(dog); 

Cat cat = Cat("Persian Cat");
GetNameAndMakeSound(cat);

```

> 类模板 Class templates 可接收类对象类型等其他任何类型
```c
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

// 类实例 Dog
Dog dog = Dog("Bulldog");
// 传入 Dog类对象实例 构造 模板类实例====
AnimalTemplate<Dog> dogTemplate(dog);
dogTemplate.GetNameAndMakeSound();

// 
Cat cat = Cat("Persian Cat");
AnimalTemplate<Cat> catTemplate(cat);
catTemplate.GetNameAndMakeSound();

```

> 标准模板库 Standard Template Library

     算法   algorithms：排序sorting、搜索searching
     容器   containers：存储数据/对象
     迭代器 iterators:  迭代器，遍历值序列，begin(),end(), 反向迭代器rbegin(),rend()
     函数   functions:  函数指针，函数对象
     

### 1.4 算法分析 
> 渐近分析 Asymptotic analysis
```c
// 该函数复杂度为 4n+1
void Looping(int n)
{
 int i = 0;    // 执行一次 赋值 
 
 while(i < n)         // 1次比较====  
 {
   cout << i << endl; // 1次打印====
   i = i + 1;         // 2次 = 1次加法 + 1次赋值===
 }
}
```

> 最坏/平均/最好情况分析 Worst, average, and best cases
```c

```

> “小于等于”O(big-Oh)  “大于等于”Ω(big-theta) “等于”Θ(big-theta)  “小于”o(little-oh)
```c

```

## 章2 列表List & 链表 Linked List===================
### 2.1 列表
>
```c
```

     
```c

```


     
```c

```


### 2.2 单向链表
>
```c
```
### 2.3 双向链表
>
```c
```
## 章3 Stack栈 和 队列Queue===========================
### 3.1 Stack栈
>
```c
```
### 3.2 队列Queue
>
```c
```
### 3.3 双端队列 Double Queue
>
```c
```
## 章4 排序算法 arranging 冒泡选择插入归并快排 ========
### 4.1 冒泡 Bubble 
>
```c
```
### 4.2 选择 Selection
>
```c
```
### 4.3 插入 Insert
>
```c
```
### 4.4 归并 Merge
>
```c
```
### 4.5 快排 Quick
>
```c
```
### 4.6 计数 Counting
>
```c
```
### 4.7 基数 Radix
>
```c
```
## 章5 查找算法 Searching 线性二分====================
### 5.1 线性 Linear search
>
```c
```
### 5.2 二分 Binary search
>
```c
```
### 5.3 三分 Ternary search
>
```c
```
### 5.4 插补 Interpolation Search 
>
```c
```
### 5.5 跳跃 Jump Search 
>
```c
```
### 5.6 指数 Exponential search
>
```c
```
### 5.7 子表 Sublist search
>
```c
```

## 章6 String 字符数据算法===========================

## 章7 树结构算法 Tree==============================
### 7.1 二叉树(Binary Tree)
[参考](https://www.cnblogs.com/eudiwffe/p/6207196.html)
```c
/*   A simple binary tree
 *        A ---------> A is root node
 *       / \
 *      /   \
 *     B     C
 *    /     / \
 *   /     /   \
 *   D     E    F ---> leaves: D, E, F
 *
 *       (1)      ---> Height: 3
 * */
```

    二叉树（Binary Tree）是最简单的树形数据结构，然而却十分精妙。
    其衍生出各种算法，以致于占据了数据结构的半壁江山。
    STL中大名顶顶的关联容器——集合（set）、映射（map）便是使用二叉树实现。
    二叉树的根节点入度为0，叶子节点出度为0。
    
    与楼房一样，一般会对二叉树分层，并且通常将根节点视为第一层。
    接下来B与C同属第二层，D, E, F同属第三层。注意，并不是所有的叶子都在同一层。
    通常将二叉树节点的最高层数作为其树的高度，上例中二叉树高度为3。
    显然，一个二叉树的节点总数必然小于2的树高幂，
    转化成公式表示为：N<2^H，其中N为节点总数，H为二叉树高度；对于第k层，最多有2^(k-1)个节点。
    
    
### 7.2 二叉搜索树(Binary Search Tree)
>
```c
```
### 7.3 平衡二叉搜索树  balanced BST (AVL)

### 7.4 二叉堆(Binary heap)
[参考](https://blog.csdn.net/Colton_Null/article/details/80963217)
>
```c
```

## 章8 哈希算法 Hash===============================
### 8.1 hash tables
>
```c
```
### 8.2
### 8.3 
### 8.4


## 章9 常用算法Real Life 贪婪&分治&动态规划&暴力&随机&回溯====
### 9.1 贪婪 Greedy algorithms
>
```c
```
### 9.2 分治 Divide and conquer algorithms
>
```c
```
### 9.3 动态规划 Dynamic programming
>
```c
```
### 9.4 暴力 Brute-force algorithms
>
```c
```
### 9.5 随机 Randomized algorithms
>
```c
```
### 9.6 回溯 Backtracking algorithms
>
```c
```

