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
[数据结构和算法动态可视化](https://visualgo.net/zh)

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
    一种包含 变量和方法的 容器 或者 集合。
    
    成员属性：
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
// 单层循环===该函数复杂度为 4n+1-------------------------------------> O(n)
void Looping(int n)
{
 int i = 0;    // 执行一次 赋值 
 
 while(i < n)         // 1次比较====  
 {
   cout << i << endl; // 1次打印====
   i = i + 1;         // 2次 = 1次加法 + 1次赋值===
 }
}

// 双层循环======  1+ n*( 1 + 1 + (4n) + 2 ) = 4n^2 + 4n +1 --------> O(n^2)
void Pairing(int n)
{
 int i = 0;   // 1次赋值 
 while(i < n) // 循环内 1次比较
 {
   int j = 0; // 循环内 1次赋值
   while(j < n) // 二层循环内 1次比较
   {
     cout << i << ", " << j << endl; // 1次打印
     j = j + 1;                      // 1次赋值 + 1次加法
   }
   i = i + 1;// 循环内 1次加法+1次赋值
 }
}

```

> 最坏/平均/最好情况分析 Worst, average, and best cases

> “小于等于”O(big-Oh)  “大于等于”Ω(big-theta) “等于”Θ(big-theta)  “小于”o(little-oh)
      
       f(n) = 4n + 1
       时间复杂度为 O(n)
       最坏情况时间复杂度 Θ(n)
       最好情况时间复杂度 Θ(1)

## 章2 列表List & 链表 Linked List===================
### 2.1 数组 array
> 内存地址连续
```c
// 直接初始化 数组
int arr[] = { 21, 47, 87, 35, 92 };

// Access each element
cout << "Array elements: ";
// 数组元素数量
int array_num = sizeof(arr)/sizeof(*arr); // 数组总元素字节数量sizeof(arr)， *arr数组首元素字节数量
for(int i = 0; i < array_num; ++i)
    cout << arr[i] << " ";
cout << endl;

// 使用下标 直接修改 数组元素
arr[2] = 30;
arr[3] = 64;

// 再次 打印 数组元素
cout << "Array elements: ";
for(int i = 0; i < array_num; ++i)
    cout << arr[i] << " ";
```

> new 分配数组，返回指针，使用指针访问元素     
```c
    // Initialize tee array length
    int arrLength = 5;

    // 使用 new 分配数组内存空间 并返回首地址指针
    int * ptr = new int[arrLength] { 21, 47, 87, 35, 92 };
    // 二维数组初始化 
    // int multiArray[][] = new int[3][5];

    // 使用 *解引用 来获取制造地址处的 值
    cout << "Using pointer increment" << endl;
    cout << "Value\tAddress" << endl;
    while(*ptr) // 不安全，数组后内地址一版存储的值为 0======
    {
        cout << *ptr << "\t"; // 解引用，获取地址处存储的值
        cout << ptr << endl;  // 打印地址
        ptr++;
    }
    cout << endl;

    // 上面的处理指针向后移动了 数组元素数量 个 存储单位
    ptr = ptr - 5;// 恢复 数组首地址的值

    // 按照数组方式 使用[] 下标索引 获取数组元素
    cout << "Using pointer index" << endl;
    cout << "Value\tAddress" << endl;
    for(int i = 0; i < arrLength; ++i)
    {
        cout << ptr[i] << "\t";  // 使用[] 下标索引 获取数组元素
        cout << &ptr[i] << endl; // & 获取 元素 的存储地址===
    }
    
    delete [] ptr;// 释放 动态申请的内存
```


### 2.2 列表List  动态内存的数组 
>
```c
// File : List.h =======================================================
#ifndef LIST_H
#define LIST_H
#include <iostream>

class List // 类
{
 private:  // 私有 变量
     int m_count;   // 元素数量
     int * m_items; // 首元素指针
     
 public:
     List();  // 类 构造函数
     ~List(); // 类 析构函数

     // 获取指定索引处的值，因为不能简单的使用连续地址函数获取指定索引处的位置的元素值
     int Get(int index);
     
     // 在 指定索引 位置 插入元素，新建一个数组，旧数组元素赋值过来，在指定位置插入 新元素======
     void Insert(int index, int val);
     
     // 在链表中搜索指定元素 val
     int Search(int val);
     
     // 删除指定索引处的 元素，新建一个数量少1的数组，除指定元素外不复制
     void Remove(int index);
     
     // 统 计链表元素数量 
     int Count();
};
#endif // LIST_H

//List.c =====================================================================
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
                                       // i每次循环 必+1-----------------------------------
    {
        if(index == i)
        {
            m_items[i] = val; // 新插入的元素 放入指定 index 位置
        }
        else
        {
            m_items[i] = oldArray[j]; // 就数组元素 放到新数组中
            ++j; // 旧数组索引 ++      // j 为非指定索引处 才+1--------------------------
        }
    }

    // 清空 旧数组 内存空间
    delete [] oldArray;
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
                                            // i,j 每次循环 必+1---
    {
        if(index == j)// 遍历到 旧数组中 指定 的 索引
        {
            ++j; // 直接跳过该 位置           // 同时指定索引处，j还会 再次+1 跳过指定元素
        }

        m_items[i] = oldArray[j];// 旧数组元素 赋值 到 新数组元素
    }

    // 清空 旧数组 内存空间
    delete [] oldArray;
}

// 完整实现 
// https://github.com/Ewenwan/CPP-Data-Structures-and-Algorithms/blob/master/Chapter02/List/src/List.cpp



// ========================使用=============================================
List list = List();

// 依次插入元素=====
list.Insert(0, 21);
list.Insert(1, 47);
list.Insert(2, 87);
list.Insert(3, 35);
list.Insert(4, 92);

// 打印元素=========
for(int i = 0; i < list.Count(); ++i)
{
    cout << list.Get(i) << " ";
}

// 查找 87
cout << "Search element 71" << endl;
int result = list.Search(71);
if(result == -1) // 没找到 返回-1
    cout << "71 is not found";
else
    cout << "71 is found at index " << result;
cout << endl << endl;

// 删除 
list.Remove(2);
    
```

### 2.3 节点链，关系网，朋友圈网，人脉圈，七大姑八大姨...
```c
// 实现===================================
class Node // 节点类，嫌疑人
{
public:
    int Value;      // 嫌疑人信息，数据值，int类型
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
    // 打印最后的 终止标志 NULL
    cout << "NULL" << endl;
}

// 使用=============================
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
    // 节点1--->节点2--->节点3--->终止NULL
    node2->Next = node3;

    // 打印 节点链，找出人脉链，挖地三尺
    PrintNode(node1);


// 节点链 模板Template 实现，可存储多种类型的数据==============================
template <typename T> // template <typename *> 模板数据类型，任意数据类型
class Node
{
public:
    T Value; // 模板类型数据
    Node<T> * Next; // 下一个节点 关系人物 模板类型节点
    
    // 类构造函数======初始化两个内部数据===
    Node(T value) : Value(value), Next(NULL) {}
};

// 打印函数也是用 模板类型=====
template<typename T>
void PrintNode(Node<T> * node)// 传入节点指针
{
    // NULL 表明 线索到头了，幕后大佬后面没老虎了===
    while(node != NULL)
    {
        cout << node->Value << " -> ";// 打印当前节点(嫌疑人)的信息(名字，脏污，财产)
        node = node->Next;            // 找到下一个嫌疑人=====
    }
    // 打印最后的 终止标志 NULL
    cout << "NULL" << endl;
}

// 使用========================================
    // +------+------+
    // | 4.93 | NULL |
    // +------+------+
    // 节点1 浮点类型数据
    Node<float> * node1 = new Node<float>(4.93);// 创建时，传入数据类型(模板类型具体化)

    // +------+------+
    // | 6.45 | NULL |
    // +------+------+
    // 节点2
    Node<float> * node2 = new Node<float>(6.45);

    // +------+------+
    // | 8.17 | NULL |
    // +------+------+
    // 节点3
    Node<float> * node3 = new Node<float>(8.17);

    // +------+------+  +------+------+  +------+------+
    // | 4.93 |   +---->| 6.45 | NULL |  | 8.17 | NULL |
    // +------+------+  +------+------+  +------+------+
    node1->Next = node2;

    // +------+------+  +------+------+  +------+------+
    // | 4.93 |   +---->| 6.45 |   +---->| 8.17 | NULL |
    // +------+------+  +------+------+  +------+------+
    // 节点1--->节点2--->节点3--->终止NULL
    node2->Next = node3;
    
    // Print the node
    PrintNode(node1);

```

### 2.4 单向链表
>
```c
// File   : Node.h 链表中的 单一节点实现，模板节点，可存储许多类型数据=================
#ifndef NODE_H
#define NODE_H

#include <iostream>

// 模板节点，可存储许多类型数据
template <typename T>
class Node
{
public:
    T Value;
    Node<T> * Next;
    // 类 构造函数 声明
    Node(T value);
};

// 类构造函数实现
// 拿到外面的话，就需要在函数前面添加 Node<T>:: 类名属性
template <typename T>
Node<T>::Node(T value) : Value(value), Next(NULL) {}

#endif // NODE_H

//==================================================
// File   : LinkedList.h   链表实现，比 节点链 多一些功能===========================
#include "Node.h"   // 单个模板节点

// 模板链表==================
template <typename T>
class LinkedList
{
private: // private 私有变量===
    int m_count; // 实际节点数量

public: // 公开方法====
    // The first node in the list or null if empty
    Node<T> * Head; // 链表表头节点

    // The last node in the list or null if empty
    Node<T> * Tail; // 链表表尾节点

    // 类构造函数 Constructor
    LinkedList();

    // 获取第 index 个 节点 Get() operation
    Node<T> * Get(int index);

    // 在链表中 插入节点 的操作===Insert() operation
    void InsertHead(T val);// 头部插入节点
    void InsertTail(T val);// 尾部插入节点
    void Insert(int index, T val);// 插入节点

    // 在链表中查找指定的值 Search() operation
    int Search(T val);

    // 删除节点的操作 ==Remove() operation===
    void RemoveHead();// 去除表头节点
    void RemoveTail();// 去除表尾节点
    void Remove(int index);// 去 链条中的节点

    // 附加操作======
    int Count();     // 节点数量 统计
    void PrintList();// 打印链表中的每一个节点的信息====
};

// 类 方法的实现方法 直接在 头文件中实现，比放在另一个cpp文件中好=========

//=================================================
//     head             ...                tail
//index  0               1                  2
// +------+------+  +------+------+  +------+------+
// | 4.93 |   +---->| 6.45 |   +---->| 8.17 | NULL |
// +------+------+  +------+------+  +------+------+
//   前置节点            目标节点          后置节点
//   prevNode             node            nextNode
//   对目标索引位置 进行 插入/删除 操作时，先找到 目标节点及其前后位置的 前置节点 和 后置节点
//=================================================

// 头部插入节点=======================
template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    // 新建一个节点====================
    Node<T> * node = new Node<T>(val);
    // 新节点的后继 指向原首节点 
    node->Next = Head;
    // 新节点重置为 首节点
    Head = node;

    // 仅有一个节点时，尾节点==首节点
    if(m_count == 0)
        Tail = Head;

    // One element is added
    m_count++;
}

// 尾部插入节点=======================
template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    // 链表为空时，和从头部插入节点一致===
    if(m_count == 0)
    {
        InsertHead(val);
        return;
    }
    
    // 新建一个节点
    Node<T> * node = new Node<T>(val);
    // 原链表的后继 设置为 新节点
    Tail->Next = node;
    // 新节点重置为 尾节点 
    Tail = node;

    // 数量++
    m_count++;
}

// 在指定位置处插入节点======================
template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
    // 检查位置index的合理性=
    if(index < 0 || index > m_count)
        return;

    // 头部插入的情况=========
    if(index == 0)
    {
        InsertHead(val);
        return;// 直接返回
    }
    // 尾部插入的情况=========
    else if(index == m_count)
    {
        InsertTail(val);
        return;// 直接返回
    }

    // 链条中间插入 节点的情况===
    // 从首节点开始 遍历到 指定位置处的 前一个节点 (找到前置节点)
    Node<T> * prevNode = Head;
    // 找到 前置节点============  断开处的 前端
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next;
    }

    // 指定位置的(后置节点)====  断开处的 后端
    Node<T> * nextNode = prevNode->Next;
    
    // 创建一个新节点==================
    Node<T> * node = new Node<T>(val);
    // 新节点后继 指向 后置节点
    node->Next = nextNode;
    // 前置节点 后继 指向 新节点
    prevNode->Next = node;

    // 数量++
    m_count++;
}

// 去除头部节点======================
template <typename T>
void LinkedList<T>::RemoveHead()
{
    // 链表 是否为空 检查
    if(m_count == 0)
        return;

    // 原 头部节点
    Node<T> * node = Head;
    // 原 头部节点的后继作为 新 首节点
    Head = Head->Next;
    // 删除原首节点
    delete node;
    
    // 仅有一个节点时，尾节点==首节点====
    if(m_count == 1)
        Tail = Head;//  新添加=========修复bug=====
    
    // 数量--
    m_count--;
}

// 去除尾部节点=========================
template <typename T>
void LinkedList<T>::RemoveTail()
{
    // 链表 是否为空 检查
    if(m_count == 0)
        return;

    // 当链表数量为1时，和去除头部节点一致
    if(m_count == 1)
    {
        RemoveHead();
        return;
    }

    // 从头节点开始，遍历到尾节点 的 前置节点，因为不能反向遍历，所以需要从头部向后遍历
    Node<T> * prevNode = Head;
    // 需要删除的节点
    Node<T> * node = Head->Next;

    // 遍历 找到指定的两个节点
    while(node->Next != NULL)// 注意是 需要删除的节点 的后继 不为 NULL
    {
        prevNode = prevNode->Next;// 前置节点
        node = node->Next;        // 需要删除的节点，即原 尾节点
    }

    // 原尾节点的 前置节点 需要 变成 新的 尾节点
    prevNode->Next = NULL; // 尾节点的后继 为 NULL
    Tail = prevNode;       // 前置节点 重置为  尾节点
    // 删除原 尾节点
    delete node;

    // 数量--
    m_count--;
}

// 删除指定索引位置的 节点
template <typename T>
void LinkedList<T>::Remove(int index)
{
    // 链表 是否为空 检查============
    if(m_count == 0)
        return;

    // 检查指定位置是否合理===========
    if(index < 0 || index >= m_count)
        return;

    // 删除头部的节点=============
    if(index == 0)
    {
        RemoveHead();
        return;// 直接返回 
    }
    //删除尾部的节点==============
    else if(index == m_count - 1)
    {
        RemoveTail();
        return;// 直接返回 
    }

    // 从 头部节点 开始 遍历
    Node<T> * prevNode = Head;

    // 找到指定 索引 前面的 前置节点
    for(int i = 0; i < index - 1; ++i)// 到index-2
    {
        prevNode = prevNode->Next;  // 前置节点 index-2 位置
    }

    // 指定节点
    Node<T> * node = prevNode->Next;// index-1 位置
    // 后置节点
    Node<T> * nextNode = node->Next;// index 位置 从0开始
    // 前置节点 的后继 设置为后置节点 跳过中间的 指定删除的节点
    prevNode->Next = nextNode;
    // 删除指定节点
    delete node;

    // 数量--
    m_count--;
}



// 使用=================================================
// NULL  创建一个空 链表 传入模板类型============
LinkedList<int> linkedList = LinkedList<int>();

// 头部插入======================
// 43->NULL
linkedList.InsertHead(43);

// 76->43->NULL
linkedList.InsertHead(76);

// 尾部插入======================
// 76->43->15->NULL
linkedList.InsertTail(15);

// 76->43->15->44->NULL
linkedList.InsertTail(44);

// 中间插入======================
// 76->43->15->44->100->NULL
linkedList.Insert(4, 100);

// 76->43->15->48->44->100->NULL
linkedList.Insert(3, 48);

// 22->76->43->15->48->44->100->NULL
linkedList.Insert(0, 22); 

// 删除节点=====================
linkedList.Remove(0);// Remove first element
// 76->43->15->48->44->100->NULL
linkedList.Remove(4);// Remove fifth element
// 76->43->15->48->100->NULL
linkedList.Remove(9);// Remove tenth element
// Nothing happen
// 76->43->15->48->100->NULL 

```

### 2.5 双向链表
>双向节点 带有 前继和后继 节点指针 DoublyNode.h
```c
// DoublyNode.h
// 双向节点 带有 前继和后继 节点指针
template <typename T>
class DoublyNode
{
// +----------+---------+---------+   
// Pre <------|  Value  | ---> Next
// +----------+---------+---------+  
    public:
        T Value; // 节点存储的信息，模板数据类型
        DoublyNode<T> * Previous; // 前继 节点指针
        DoublyNode<T> * Next;     // 后继 节点指针
        
        // 类对象 构造函数 声明
        DoublyNode(T value);      
};

// 类对象 构造函数 实现 
template <typename T>
DoublyNode<T>::DoublyNode(T value)
    // 值，前继和后继 节点指针 为NULL
    : Value(value), Previous(NULL), Next(NULL) {}
```

> 双向链表 有双向节点构成的 双向索引链条  在插入/删除节点时需要考虑 设置前继和后继节点的指针
```c
// https://github.com/Ewenwan/CPP-Data-Structures-and-Algorithms/blob/master/Chapter02/Doubly_Linked_List/include/DoublyLinkedList.h

template <typename T>
class DoublyLinkedList
{
    private: // 私有数据
        int m_count;// 双向节点 数量记录

    public:
        // 双向链表头
        DoublyNode<T> * Head;

        // 双向链表尾
        DoublyNode<T> * Tail;

        // 构造函数===========
        DoublyLinkedList();

        // 获取指定索引上的双向节点 Get() operation
        DoublyNode<T> * Get(int index);

        // 双向链表插入操作 Insert() operation
        void InsertHead(T val);// 表头插入
        void InsertTail(T val);// 表尾插入
        void Insert(int index, T val);// 普通插入函数

        //查找数据信息 Search() operation
        int Search(T val);

        // 双向链表删除节点操作 Remove() operation
        void RemoveHead();
        void RemoveTail();
        void Remove(int index);

        // 附加操作 Additional operation
        int Count();       // 计数 
        void PrintList();  // 正向打印 双向链表
        void PrintListBackward();// 反向打印 双向链表
};

// 实现===================================================
// 表头插入节点==================================
template <typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
    // 新建节点
    DoublyNode<T> * node = new DoublyNode<T>(val);
    
    // 连接处 互相指向===========each other======
    // 新节点的后继 指向原 链表表头
    node->Next = Head;
    // 如果原 头结点存在，则原头结点的 前继 需要指向 新节点(作为新表头)
    if(Head != NULL)
        Head->Previous = node;

    // 新节点 重置为 链表表头
    Head = node;

    // 如果链表中只有一个节点，那么 表尾 == 表头
    if(m_count == 0)
        Tail = Head;

    // One element is added
    m_count++;
}

// 表尾插入节点=============================
template <typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
    // 链表为空时，和表头插入一致
    if(m_count == 0)
    {
        InsertHead(val);
        return;
    }

    // 新建一个节点
    DoublyNode<T> * node = new DoublyNode<T>(val);
    // 原尾节点 的 后继 设置为 新节点  // 注意需要双向关联
    Tail->Next = node;
    // 新节点的 前继 设置为 原尾节点
    node->Previous = Tail;
    // 新节点 重置为 链表的 尾节点
    Tail = node;

    // 数量++
    m_count++;
}
// 一般位置插入节点===================
template <typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
    // 插入位置 范围检查
    if(index < 0 || index > m_count)
        return;

    // 在头部插入====
    if(index == 0)
    {
        InsertHead(val);
        return;
    }
    // 在尾部插入=====
    else if(index == m_count)
    {
        InsertTail(val);
        return;
    }

    // 目标位置的 前置节点
    DoublyNode<T> * prevNode = Head;

    // 遍历到 前置节点
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next; // 0,...,index-2
    }

    // 后置节点 
    DoublyNode<T> * nextNode = prevNode->Next;//0,...,index-1

    // 创建一个新的节点
    DoublyNode<T> * node = new DoublyNode<T>(val);

    // 需要重新设置4个指向======
    // prevNode----> node ------>nextNode
    // prevNode<---- node <----- nextNode
    node->Next = nextNode;     // 1.               node ------>nextNode
    node->Previous = prevNode; // 2. prevNode<---- node
    prevNode->Next = node;     // 3. prevNode----> node
    nextNode->Previous = node; // 4.               node <----- nextNode

    // One element is added
    m_count++;
}


// 双向链表中 删除节点===============================================
template <typename T>
void DoublyLinkedList<T>::RemoveHead()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // 原 链表头
    DoublyNode<T> * node = Head;

    // 原 链表头后继 设置为 新链表头
    Head = Head->Next;

    // 删除原链表头
    delete node;

    // 设置 表头前置 节点为 NULL
    if(Head != NULL)
        Head->Previous = NULL;

    // 数量--
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::RemoveTail()
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;

    // If List element is only one
    // just simply call RemoveHead()
    if(m_count == 1)
    {
        RemoveHead();
        return;
    }

    // 原表尾节点
    DoublyNode<T> * node = Tail;

    // 可以反向遍历 找到 原表尾节点的 前置节点，并设置为 新的表尾节点
    Tail = Tail->Previous;

    // 表尾节点的后继设置为 NULL
    Tail->Next = NULL;

    // 删除原 链表表尾节点
    delete node;

    // 数量--
    m_count--;
}

template <typename T>
void DoublyLinkedList<T>::Remove(int index)
{
    // 链表为空检查
    if(m_count == 0)
        return;

    // 指定位置索引 范围检查
    if(index < 0 || index >= m_count)
        return;

    // 删除表头结点
    if(index == 0)
    {
        RemoveHead();
        return;
    }
    // 删除表尾节点
    else if(index == m_count - 1)
    {
        RemoveTail();
        return;
    }

    // 指定位置 的 前置节点
    DoublyNode<T> * prevNode = Head;
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->Next; // 0,...,index-2
    }
    // 需要删除的 目标节点
    DoublyNode<T> * node = prevNode->Next; // 0,...,index-1

    // 目标节点 后  的 后置节点
    DoublyNode<T> * nextNode = node->Next; // 0,...,index

    // 新增两个指向   前置节点 ---->  后置节点
    //               前置节点 <----  后置节点
    prevNode->Next = nextNode;     // 前置节点 ---->  后置节点
    nextNode->Previous = prevNode; // 前置节点 <----  后置节点

    // 删除目标节点
    delete node;

    // 数量--
    m_count--;
}

```

### 2.6 STD 中的列表List 和 链表LinkedList
     列表 List                   : std::vector
     单向链表 SinglyLinkedList   : std::forward_list
     双向链表 DoublyLinkedList   : std::list
```c
//====================================================================
// 列表 向量 vector====================================
vector<int> vectorlist = { 35, 41, 94 }; // 列表初始化

// push_back() 方式插入
vector<int> vectorList2;
vectorList2.push_back(35);
vectorList2.push_back(41);
vectorList2.push_back(94);

// 获取=
int i = vectorList.at(1); // 带安全检查
int j = vectorList[0];    // 不带安全检查

// 迭代器 方式获取 元素=============================
vector<int>::iterator itr;
itr = vectorList.begin();
vectorList.insert(itr, 58);// 表头插入 节点
itr = vectorList.end();    // 尾部 迭代器 实际上是 一个位置哨兵，实际上不存在
vectorList.insert(itr, 37);// 表尾插入 节点

itr = vectorList.begin();
vectorList.insert(itr + 3, 67);//第四个位置插入元素

// 查找元素==========================================
itr = find (vectorList.begin(), vectorList.end(), 41);
if (itr != vectorList.end())
 cout << "Element found in vectorList: " << *itr;
else
 cout << "Element not found in vectorList"; // 未找到
cout << endl << endl;

// 删除第二个元素 ==========================
itr = vectorList.begin();
vectorList.erase (itr + 1);

// ===============================================================
// 双向链表list=========

void PrintLinkedList(const list<int>& llist)
{
    for (auto l : llist) // 范围for循环
    {
        std::cout << l << " -> "; // 打印每个节点元素
    }
    cout << "NULL" << endl;
}

// 获取指定位置 迭代器====
list<int>::iterator GetIterator(list<int>::iterator it, int x)
{
    for(int i = 0; i < x; ++i, ++it);
    return it;
}

    // 初始化一个 list
    list<int> linkedList;

    // 43->NULL
    linkedList.push_front(43);

    // 76->43->NULL
    linkedList.push_front(76);

    // 76->43->15->NULL
    linkedList.push_back(15);

    // 76->43->15->44->NULL
    linkedList.push_back(44);
    
    // 打印 链表
    PrintLinkedList(linkedList);
    
    //              插入元素=====
    // 76->43->15->44->100->NULL
    list<int>::iterator itr = GetIterator(linkedList.begin(), 4);
    linkedList.insert(itr, 100);
    
    // 查找元素====
    itr = find (linkedList.begin(), linkedList.end(), 15);
    if (itr != linkedList.end())
        cout << "Element found in linkedList: " << *itr;
    else
        cout << "Element not found in linkedList";
    cout << endl << endl;
    
    // 删除元素====
    itr = linkedList.begin();
    linkedList.erase (itr);
    // 43->15->44->100->NULL
    
    
```
## 章3 Stack栈 和 队列Queue===========================

### 3.1 Stack栈  叠起来的 碗，放在一摞的书...都是栈的实例...
    一种 插入 和 删除 操作只能在一端( 栈顶Top() )进行的 容器
    是一种 后进先出(Last In First Out, LIFO) 的数据结构
![](https://github.com/Ewenwan/CPP-Data-Structures-and-Algorithms/blob/master/fig/stack.PNG)

>
```c
// Stack.h =========================
template <typename T> // 模板类型
class Stack
{
private:   // 私有数据
 int m_count;// 熟练
 Node<T> * m_top; // 栈顶指针
 
 
public: // 公开
 Stack();       // 类构造函数
 bool IsEmpty();// 空检查
 T Top();       // 获取栈顶元素
 void Push(T val);// 栈顶插入元素
 void Pop();      // 弹出栈顶元素
};

// 获取栈顶元素=======
template <typename T>
T Stack<T>::Top()
{
 // Just return the value of m_top node
 return m_top->Value;
}

// 空检查===============
template <typename T>
bool Stack<T>::IsEmpty()
{
 // return TRUE if there are no items
 // otherwise, return FALSE
 return m_count <= 0;
}

// 栈顶插入元素===========
template <typename T>
void Stack<T>::Push(T val)
{
 // 创建一个新节点
 Node<T> * node = new Node<T>(val);
 // 新节点的 后继 指向 原 栈顶节点
 node->Next = m_top;
 // 新节点 重置为 新栈顶节点
 m_top = node;
 // 数量++
 m_count++;
}

// 弹出栈顶元素===========
template <typename T>
void Stack<T>::Pop()
{
 // 空栈直接返回
 if(IsEmpty())
      return;
 // 旧栈顶节点，待删除
 Node<T> * node = m_top;
 // 旧栈顶节点的后继 设置为 新栈顶节点
 m_top = m_top->Next;
 // 删除原 旧栈顶节点
 delete node;
 // 数量--
 m_count--;
}

// 使用===============
 // 初始化一个空栈 NULL
 Stack<int> stackInt = Stack<int>();
 // Store several numbers to the stack
 stackInt.Push(32);
 stackInt.Push(47);
 stackInt.Push(18);
 stackInt.Push(59);
 stackInt.Push(88);
 stackInt.Push(91);
 // 32->47->18->59->88->91|
 while(!stackInt.IsEmpty())
 {
 // 打印栈顶 节点 信息
 cout << stackInt.Top() << " ->";
 // 删除栈顶节点
 stackInt.Pop();
 }
 cout << "END" << endl;

```

> 栈典型应用  括号匹配 { ( ) [ { } ] }

    { ( ) [ { } ] }
    1. 遇到左括号 入栈
    2. 遇到右括号 检查 栈顶值 符号是否匹配，若匹配则对应左括号出栈
    3. 最后 符号字符串读完，左括号栈 为空，则该符号串有效
```c
bool IsValid (char expression[])
{
 int n = strlen(expression);
 Stack<char> stackChar = Stack<char>(); // 左符号 栈
 for (int i = 0; i < n; ++i)
 {
     // 遇到左符号 入栈
     if(expression[i] == '{')
     {
         stackChar.Push('{');
     }
     else if(expression[i] == '[')
     {
         stackChar.Push('[');
     }
     else if(expression[i] == '(')
     {
         stackChar.Push('(');
     }
     // 遇到右括号
     else if ( expression[i] == '}' ||
               expression[i] == ']' ||
               expression[i] == ')')
     {
         // 
         if(expression[i] == '}' &&
         (stackChar.IsEmpty() || stackChar.Top() != '{'))
             // 对应 右 } 应该匹配 { 否者 该字符串 非法
             return false;
         else if(expression[i] == ']' &&
         (stackChar.IsEmpty() || stackChar.Top() != '['))
             return false;
         else if(expression[i] == ')' &&
         (stackChar.IsEmpty() || stackChar.Top() != '('))
             return false;
         // 对应匹配的 左符号出栈======
         else
             stackChar.Pop();
     }
 }
 
 // 字符串遍历完后，左括号栈 为空，说明所有左右符号已经全部匹配，该字符串合法
 if (stackChar.IsEmpty())
     return true; //
 else
     return false;
}
```

### 3.2 队列Queue
    
    一种只能从一端插入元素，从另一端删除元素的 容器
    First In First Out(FIFO) 先入先出 队列
    现实世界中的 排队，打印机队列...都是队列的实例
    队首----->...---->首尾--->新节点
![](https://github.com/Ewenwan/CPP-Data-Structures-and-Algorithms/blob/master/fig/queue.PNG)
> 先入先出 队列

```c
// https://github.com/Ewenwan/CPP-Data-Structures-and-Algorithms/blob/master/Chapter03/Queue/include/Queue.h
template <typename T>
class Queue
{
private:
    int m_count; // 节点数量
    Node<T> * m_front; // 前端节点(队首) 指针 删除元素入口
    Node<T> * m_back;  // 后端节点(队尾) 指针 插入元素入口

public:
    Queue();// 构造函数
    bool IsEmpty();// 为空检查
    T Front();     // 获取 队首 元素
    void Enqueue(T val); // 从队尾 插入元素
    void Dequeue();      // 从队首 删除元素
};

// 队尾插入元素
template <typename T>
void Queue<T>::Enqueue(T val)
{
    // 新建一个节点
    Node<T> * node = new Node<T>(val);

    if(m_count == 0)
    {
        // 为空时，新建的一个节点 即为队首也为队尾节点===
        node->Next = NULL;
        m_front = node;
        m_back = m_front;
    }
    else
    {
        // 队首----->...---->首尾--->新节点
        m_back->Next = node;
        // 新节点变成 新 队尾
        m_back = node;
    }

    // 数量++
    m_count++;
}

// 队首删除元素
template <typename T>
void Queue<T>::Dequeue()
{
    // 空
    if(m_count == 0)
        return;

    // 原队首节点
    Node<T> * node = m_front;
    // 原队首节点的后继 设置为 新队首
    m_front = m_front->Next;
    // 删除 原队首节点
    delete node;

    // 数量--
    m_count--;
}


// =================使用====
    // 创建新队列 NULL
    Queue<int> queueInt = Queue<int>();

    // 队尾插入元素=====
    queueInt.Enqueue(35);
    queueInt.Enqueue(91);
    queueInt.Enqueue(26);
    queueInt.Enqueue(78);
    queueInt.Enqueue(44);
    queueInt.Enqueue(12);

    // 从队首 依次打印 并删除 节点
    while(!queueInt.IsEmpty())
    {
        // 打印 队首 元素
        cout << queueInt.Front() << " - ";

        // 删除 节点
        queueInt.Dequeue();
    }
    cout << "END" << endl;

```

### 3.3 双端队列 Double Queue   双向节点构成 
![](https://github.com/Ewenwan/CPP-Data-Structures-and-Algorithms/blob/master/fig/deque.PNG)
  
  可以从两端进行插入和删除操作

>双端队列 Double Queue
```c
// https://github.com/Ewenwan/CPP-Data-Structures-and-Algorithms/blob/master/Chapter03/Deque/include/Deque.h
template <typename T>
class Deque
{
private:
    int m_count; // 数量
    DoublyNode<T> * m_front;// 队首节点指针  双向节点
    DoublyNode<T> * m_back; // 队尾节点指针

public:
    Deque();
    bool IsEmpty();
    T Front();
    T Back();
    void EnqueueFront(T val); // 队首插入元素 新节点后继指向原队首，原队首前继指向新节点，新节点作为新队首  
    void EnqueueBack(T val);  // 队尾插入元素 原队尾后继指向新节点  新节点前继指向原队尾，新节点作为新队尾
    void DequeueFront();      // 队首删除元素 保存旧队首，旧队首后继作为新队首，新队首前继指向NULL，删除旧队首
    void DequeueBack();       // 队尾删除元素 保存旧队尾，旧队尾前继作为新队尾，新队尾后继指向NULL，删除旧队尾
};
```
## 章4 排序算法 arranging 冒泡选择插入归并快排 ========
### 4.1 冒泡 Bubble 
    每次从剩余序列中找出最大值，最大值依次交换到最右端
    改进1：其中如果未发送交换则序列已经有序，可提前结束
    改进2：其中每次的变量交换找最大值 只需要遍历到 上次变量中最后一个交换的位置(该部分已经有序)，跳过已经有序的部分
>
```c
void BubbleSort(int arr[], int arrSize)
{
    // 是否有序标志
    bool isSwapped;
    int SwapIndex;
    // 未排序元素数量
    int unsortedElements = arrSize;
    do
    {
        // 是否发生交换的标志
        isSwapped = false;
        SwapIndex=0;
        // Iterate through the array's element
        for(int i = 0; i < unsortedElements - 1; ++i)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);// 大的放在右边
                isSwapped = true;
                SwapIndex=i+1;// 已经有序的位置
            }
        }

        if(SwapIndex)
            unsortedElements=SwapIndex+1; // 跳过已经有序的部分===================改进=====
        else
            --unsortedElements;
    }
    // 如果未发生交换，则原序列已经 有序了===可提前结束排序过程
    while(isSwapped);
}
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

