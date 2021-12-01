## 自我介绍
我叫陈吴彬，喜欢C# (
***
## 最喜欢的游戏类型
我最喜欢玩的是沙盒类游戏与大战略游戏  
其中最喜欢的应该是<u>**钢铁雄心4**</u>，因为其具有极高可扩展性，在**KR、KX、RF、TNO**等mod的加持下拥有无尽的可能性与故事性，~~(而且可以自己做mod编故事)~~

***
## Unity生命周期函数
+ **生命周期调用顺序图**  
![调用表](https://img-blog.csdnimg.cn/2019031116100080.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzM0NzkxNjMy,size_16,color_FFFFFF,t_70 "QAQ")
+ **主要生命周期调用顺序**  
Awake()——>Start()——>Update()——>FixedUpdate()——>LateUpdate()——>OnGUI()——>Reset()——>OnDisable()——>OnDestroy()
***
## 基础知识学习笔记
**C++模板相关知识与泛式编程**

在 C++ 中，模板是泛型编程的基础。模板是创建类或函数的蓝图或公式。

模板定义以关键字 template 开始，后接模板形参表，模板形参表是用尖括号括住的一个或多个模板形参的列表，形参之间以逗号分隔，模板形参表不能为空

+ 模板的格式:

```c++
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```
```c++
template<class T1,class T2,...> 
    return_val function_name (para1,para1,...)
{
}
```

```c++
template <class T1,class T2,...>
    class class_name
    {
    };
```

+ 普通函数和模板函数的区别:
	- 当普通函数和模板函数同名时：
		- 编译器优先调用普通函数
		- 如果想要优先调用模板函数：加上<>
	- 自动类型推到
		- ：普通函数可以允许自动类型转化
		- ：模版函数不可以自动类型转化

+ 模板的匹配原则:

​		如果有定义出来的函数,且类型完全匹配调用时实参类型,则执行定义出来的函数.

​		如果定义出来的函数,不符合,则执行模板推演.