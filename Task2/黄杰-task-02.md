# 我的自我介绍
我是来自信息安全2102的黄杰，平时喜欢打打游戏，打打球，也会看一些猛男番
# 我最喜欢的游戏类型
目前为止，我最喜欢的游戏类型是开放世界类型的游戏，但最喜欢的游戏是lol和原神。
对于一个优秀游戏而言，我认为不仅需要由丰富的游戏性，也要有一个完善且自洽的世界观，这里包括但不限于音乐，美术等方面。因为游戏可以不仅仅只是一个娱乐的工具，它也能成为一个传达创作者思想的工具。
玩一款好游戏，不仅能让人身心放松，也可以让玩家与开发者进行交流，传达思想，这点就像是读一本书一样。游戏也能成为一种艺术，而原神这个游戏不管是游戏性也好，画质也罢，都属于上乘作品，而他对于世界观的塑造
则是我最喜欢的一点，音乐也好，建筑也好，都可以与现实发生共鸣，让人能感觉到这些风格是由文化底蕴在的。至于lol，或许是我这一代部分人的信仰罢了，但它最近对于自身世界观补充的作品双城之战也让人眼前一亮。
但我游玩的游戏不多，仅仅只是在我认知范围内罗列的两个游戏，仅代表个人意见。
# unity的函数
awake（）：当一个脚本实例被载入时Awake被调用。用于初始化游戏状态，在脚本整个生命周期内它仅被调用一次（ps：在start（）函数之前）

start（）：Start仅在Update函数第一次被调用前调用。Start在behaviour的生命周期中只被调用一次。

onenable（）：当对象变为可用或激活状态时此函数被调用。

reset（）：Reset是在用户点击检视面板的Reset按钮或者首次添加该组件时被调用。

fixedupdate（）/update()：当MonoBehaviour启用时，其在每一帧被调用，都是用来更新的。

ontrigger():老熟人了，进入触发器void OnTriggerEnter (Collider other) 当Collider(碰撞体)进入trigger(触发器)时调用OnTriggerEnter。

            逗留触发器void OnTriggerStay (Collider other) 当碰撞体接触触发器时，OnTriggerStay将在每一帧被调用。
            
            退出触发器void OnTriggerExit  (Collider other)当Collider(碰撞体)停止触发trigger(触发器)时调用OnTriggerExit。
ondestroy():当MonoBehaviour将被销毁时，这个函数被调用。

ondisable():当对象变为不可用或非激活状态时此函数被调用。当物体被销毁时它将被调用，并且可用于任意清理代码。脚本被卸载时，OnDisable将被调用，OnEnable在脚本被载入后调用。
            
# c++的模板类

与模板函数相似，模板类可以看成类的模板，用于实现作用相同但数据类型不同的过程。

## 基础的类模板

类模板，可以定义相同的操作，拥有不同数据类型的成员属性。

通常使用`template`来声明。告诉编译器，碰到`T`不要报错，表示一种泛型。

如下：

```c++
template <typename T>
class Complex{
    
public:
    //构造函数
    Complex(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    
    //运算符重载
    Complex<T> operator+(Complex &c)
    {
        Complex<T> tmp(this->a+c.a, this->b+c.b);
        return tmp;
    }
        
private:
    T a;
    T b;
}
 
int main()
{
    //对象的定义，必须声明模板类型，因为要分配内容
    Complex<int> a(10,20);  
    Complex<int> b(20,30);
    Complex<int> c = a + b;
    
    return 0;
}

```

## 模板类的继承

在模板类的继承中，需要注意以下两点：

- 如果父类自定义了构造函数，记得子类要使用构造函数列表来初始化
- 继承的时候，如果子类不是模板类，则必须指明当前的父类的类型，因为要分配内存空间
- 继承的时候，如果子类是模板类，要么指定父类的类型，要么用子类的泛型来指定父类

```c++
template <typename T>
class Parent{
public:
    Parent(T p)
    {
        this->p = p;
    }
    
private:
    T p;
};
 
//如果子类不是模板类，需要指明父类的具体类型
class ChildOne:public Parent<int>{
    
public:
    ChildOne(int a,int b):Parent(b)
    {
        this->cone = a;
    }
    
private:
    int cone;
};
 
 
//如果子类是模板类，可以用子类的泛型来表示父类
template <typename T>
class ChildTwo:public Parent<T>{
    
public:
    ChildTwo(T a, T b):Parent<T>(b)
    {
        this->ctwo = a;
    }
    
private:
    T ctwo;
};

```

#
