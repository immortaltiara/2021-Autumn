##  *自我介绍*

-  姓名:陆君仪

-  爱好：敲代码、钓鱼、看动漫

- 家乡：江苏 南通

-  未来打算：努力学习，考研华师

- 方向:游戏开发

## *最喜欢的游戏类型及具体游戏*

- 游戏类型：2D冒险类闯关类游戏
- 具体游戏:超级马里奥
- 喜欢原因：个人喜欢像素风格，充满童年回忆，也很好玩

## Unity生命周期函数以及调用时间

```c#
void Reset(){}//Reset是在用户点击检视面板的Reset按钮或者首次添加该组件时被调用。此函数只在编辑模式下被调用。Reset最常用于在检视面板中给定一个最常用的默认值。
```

```c#
void Awake(){}//当一个脚本实例被载入时Awake被调用。
```

```c#
void OnEnable(){}//当对象变为可用或激活状态时此函数被调用。
```

```c#
void Start(){}//Start仅在Update函数第一次被调用前调用。
Start在behaviour的生命周期中只被调用一次。
```

```c#
void FixedUpdate(){}//基于物理游戏行为一般用该方法，处理Rigidbody时，需要用FixedUpdate代替Update
```

```c#
void OnTriggerXXX(Collider other)
{
    OnTriggerEnter (Collider other);//进入触发器
    OnTriggerStay (Collider other);//逗留触发器
    OnTriggerExit (Collider other);//退出触发器
}
```

```c#
void OnCollisionXXX (Collision collisionInfo)
{
    OnCollisionEnter (Collision collisionInfo);//进入碰撞
    OnCollisionStay (Collision collisionInfo);//逗留碰撞
    OnCollisionExit (Collision collisionInfo);//退出碰撞
}
```

```c#
void OnMouseXXX()
{
 OnMouseUp ();//当用户释放鼠标按钮时调用OnMouseUp。OnMouseUp只调用在按下的同一物体上
 OnMouseDown ();//当鼠标在Collider(碰撞体)上点击时调OnMouseDown。
 OnMouseEnter ();//当鼠标进入到Collider(碰撞体)中时调用OnMouseEnter。
 OnMouseExit ();//当鼠标移出Collider(碰撞体)上时调用OnMouseExit。
 OnMouseOver ();//当鼠标悬浮在Collider(碰撞体)上时调用 OnMouseOver;
}
```

```c#
void Update (){}//当MonoBehaviour启用时，其Update在每一帧被调用。Update是实现各种游戏行为最常用的函数。
```

```c#
void LateUpdate(){}//当Behaviour启用时，其LateUpdate在每一帧被调用。
LateUpdate是在所有Update函数调用后被调用。
```

```c#
void OnDrawGizmos(){}//只在编辑模式下被调用,用于在场景视图中绘制小图示 (Gizmos)，以实现可视化目的
```

```c#
void OnApplicationPause(){}//在程序检测到暂停时，会在帧的结尾被调用
```

```c#
void OnDisable (){}//当对象变为不可用或非激活状态时此函数被调用。当物体被销毁时它将被调用，并且可用于任意清理代码。脚本被卸载时，OnDisable将被调用，OnEnable在脚本被载入后调用。
```

```c#
void OnDestroy (){}//当MonoBehaviour将被销毁时，这个函数被调用。OnDestroy只会在预先已经被激活的游戏物体上被调用
```

## *Markdown语法学习笔记*

### Headers标题

\#H1 或者（===）

##H2或者（---）

###H3

####H4

#####H5

######H6

### Emphasis

1个*对，表示斜体

2个*对，表示加粗

3个*对，表示斜粗

### List

#### *无序*

可以用*，+，-表示

#### *有序*

1. 第一行 

2. 第二行 

3. 第三行
### Links

Inline-style 内嵌方式：[W3Cschool](http://www.w3cschool.cn/ "W3Cschool")

Reference-style 引用方式：[链接文字][id]

Relative reference to a repository file 引用存储文件：[链接文字](../path/file/readme.text "标题文字")

Email 邮件：<example@w3cschool.cn>

### Images

Inline-style 内嵌方式：![替代文字](http://statics.w3cschool.cn/images/w3c/index-logo.png "标题文字")

Reference-style 引用方式：

```
![替代文字][logo]
[logo]: http://statics.w3cschool.cn/images/w3c/index-logo.png "标题文字"
```

