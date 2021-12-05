# 考核二

### 自我介绍：李秾，男，软件20级

### 最喜欢的游戏类型：暂无

玩的**最多**的游戏类型：MOBA  SLG  LOL 王者

**原因**：接触早，社交环境，简单易上手，有该类型的游戏经验

## Unity的生命周期函数，以及调用区间：

>主要执行顺序
>`编辑器->初始化->物理系统->输入事件->游戏逻辑->场景渲染->GUI渲染->物体激活或禁用->销毁物体->应用结束`

> 主要函数介绍
> `Reset是在用户点击检视面板的Reset按钮或者首次添加该组件时被调用。此函数只在编辑模式下被调用。Reset最常用于在检视面板中给定一个最常用的默认值。`

> > `Awake用于在游戏开始之前初始化变量或游戏状态。在脚本整个生命周期内它仅被调用一次.Awake在所有对象被初始化之后调用，所以你可以安全的与其他对象对话或用诸如 GameObject.FindWithTag 这样的函数搜索它们。每个游戏物体上的Awke以随机的顺序被调用。因此，你应该用Awake来设置脚本间的引用，并用Start来传递信息 ,Awake总是在Start之前被调用。它不能用来执行协同程序。`

> > > `OnDisable不能用于协同程序。当对象变为不可用或非激活状态时此函数被调用。`

> > >`Start在behaviour的生命周期中只被调用一次。它和Awake的不同是Start只在脚本实例被启用时调用。你可以按需调整延迟初始化代码。Awake总是在Start之前执行。这允许你协调初始化顺序。`

> > > `FixedUpdate ,当MonoBehaviour启用时，其在每一帧被调用。处理Rigidbody时，需要用FixedUpdate代替Update。例如:给刚体加一个作用力时，你必须应用作用力在FixedUpdate里的固定帧，而不是Update中的帧。(两者帧长不同)。`

> > > `OnTriggerEnter可以被用作协同程序，在函数中调用yield语句。当Collider(碰撞体)进入trigger(触发器)时调用OnTriggerEnter。`

> > >`OnCollisionEnter相对于OnTriggerEnter，传递的是Collision类而不是Collider。Collision包含接触点，碰撞速度等细节。如果在函数中不使用碰撞信息，省略collisionInfo参数以避免不必要的运算。注意如果碰撞体附加了一个非动力学刚体，只发送碰撞事件。可以被用作协同程序。`

> >`当鼠标在GUIElement(GUI元素)或Collider(碰撞体)上点击时调用OnMouseDown。`

> > `Update是实现各种游戏行为最常用的函数。`

> > >`一个协同程序在执行过程中,可以在任意位置使用yield语句。yield的返回值控制何时恢复协同程序向下执行。协同程序在对象自有帧执行过程中堪称优秀。协同程序在性能上没有更多的开销。StartCoroutine函数是立刻返回的,但是yield可以延迟结果。直到协同程序执行完毕。`

> > >`LateUpdate是在所有Update函数调用后被调用。这可用于调整脚本执行顺序。例如:当物体在Update里移动时，跟随物体的相机可以在LateUpdate里实现。`

> > >`渲染和处理GUI事件时调用。这意味着你的OnGUI程序将会在每一帧被调用。要得到更多的GUI事件的信息查阅Event手册。如果Monobehaviour的enabled属性设为false，OnGUI()将不会被调用。`

> > `OnApplicationQuit，当用户停止运行模式时在编辑器中调用。当web被关闭时在网络播放器中被调用。`

## 基础知识学习笔记

使用 **#** 号可表示 1-6 级标题，一级标题对应一个 **#** 号，二级标题对应两个 **#** 号，以此类推。  

**段落的换行是使用两个以上空格加上回车**。

```
*斜体文本*
_斜体文本_
**粗体文本**
__粗体文本__
***粗斜体文本***
___粗斜体文本___
```

可以在一行中用三个以上的星号、减号、底线来建立一个分隔线，行内不能有其他东西。你也可以在星号或是减号中间插入空格。

无序列表使用星号(*****)、加号(**+**)或是减号(**-**)作为列表标记，这些标记后面要添加一个空格，然后再填写内容。

![image-20211205190637410](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20211205190637410.png)

代码区块使用 **4 个空格**或者一个**制表符（Tab 键）**。

Markdown 图片语法格式如下：

```
![alt 属性文本](图片地址)

![alt 属性文本](图片地址 "可选标题")
```

Markdown 制作表格使用 **|** 来分隔不同的单元格，使用 **-** 来分隔表头和其他行。

语法格式如下：

```
|  表头   | 表头  |
|  ----  | ----  |
| 单元格  | 单元格 |
| 单元格  | 单元格 |
```

## C++模板及其泛式编程

模板**类型参数**可以定义返回类型或函数的参数类型，以及在函数体内用于变量声明或类型转换：

```text
template <typename T, typename U> 
T foo (T* p) {
    T tmp = *p;
    ...
    return tmp;
}
```

**非类型的模板参数**

一个非类型参数表示一个**值**而非一个**类型**，我们通过一个**特定的类型名**而非`typename`。非类型参数被用户提供的或编译器推断出的值所替代，这些值必须是[常量表达式](https://www.zhihu.com/search?q=常量表达式&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A269950476})。我们编写一个`compare`处理字符串字面量，可以**推导**出一个数组的**长度**的模板，因为我们可能要**用到**这些数组的长度：

```text
template <unsigned N, unsigned M>
bool compare(const char (&p1) [N], const char (&p2) [M])
{
    return N > M;
}
```

**模板类型参数**
      `一般来说，我们可以将类型参数看作类型说明符，就像内置类型或类类型说明符一样使用。特别是，类型参数可以用来指定返回类型或函数的参数类型，以及在函数体内用于变量声明或类型转换。类型参数前必须使用关键字class或typename在模板参数列表中，这两个关键字含义相同，可以互相使用，一个模板参数列表中可以同时使用这两个关键字。建议使用typename.`

**非类型模板参数**
   `    除了定义类型参数，还可以在模板中定义非类型参数，一个非类型参数表示一个值而非一个类型。我们通过一个特定的类型名而非关键字class或typename来指定非类型参数。`

       当一个模板被实例化时，非类型参数被一个用户提供的或编译器推断出的值所代替。这些值必须是常量表达式，从而允许编译器在编译时实例化模板。

**inline和constexpr的函数模板**

     函数模板可以声明为inline或constexpr的，如同非模板函数一样，inline或constexpr说明符放在模板参数列表之后，返回类型之前。

### GIT学习

1.创建版本库

第一步，创建一个空目录

$ mkdir learngit

$ cd learngit

$ pwd

/目录

如果你使用Windows系统，为了避免遇到各种莫名其妙的问题，请确保目录名（包括父目录）不包含中文。

pwd命令用于显示当前目录

第二步，通过git init命令把这个目录变成Git可以管理的仓库：

$ git init

Initialized empty Git repository in /目录/.git/

2.编写一个readme.txt文件，内容如下：一定要放到learngit目录下（子目录也行）

Git is a version control system.

Git is free software.

windows创建版本库时，从输入状态退出,esc-shift+";"-wq

第一步，用命令git add告诉Git，把文件添加到仓库：

$ git add readme.txt

第二步，用命令git commit告诉Git，把文件提交到仓库：

$ git commit -m "wrote a readme file"

[master (root-commit) eaadf4e] wrote a readme file

 1 file changed, 2 insertions(+)

 create mode 100644 readme.txt

简单解释一下git commit命令，-m后面输入的是本次提交的说明，可以输入任意内容。

为什么Git添加文件需要add，commit一共两步呢？因为commit可以一次提交很多文件，所以你可以多次add不同的文件，比如：

$ git add file1.txt

$ git add file2.txt file3.txt

$ git commit -m "add 3 files."

3.修改文件

到指定目录下vi readme.txt 按i进入编辑模式

Git is a distributed version control system.

Git is free software.

运行git status命令看看结果：

$ git status

On branch master

Changes not staged for commit:

 (use "git add <file>..." to update what will be committed)

 (use "git checkout -- <file>..." to discard changes in working directory)

 

​	modified:  readme.txt

 

no changes added to commit (use "git add" and/or "git commit -a")

git status命令可以让我们时刻掌握仓库当前的状态，上面的命令输出告诉我们，readme.txt被修改过了，但还没有准备提交的修改。

看看具体修改了什么内容,要用git diff这个命令看看：

$ git diff readme.txt 

diff --git a/readme.txt b/readme.txt

index 46d49bf..9247db6 100644

--- a/readme.txt

+++ b/readme.txt

@@ -1,2 +1,2 @@

-Git is a version control system.

+Git is a distributed version control system.

 Git is free software.

git diff顾名思义就是查看difference，显示的格式正是Unix通用的diff格式，可以从上面的命令输出看到，我们在第一行添加了一个distributed单词。

提交之后再用git status命令看看仓库的当前状态：

$ git status

On branch master

nothing to commit, working tree clean

Git告诉我们当前没有需要提交的修改，而且，工作目录是干净（working tree clean）的。

4.版本回退

版本控制系统肯定有某个命令可以告诉我们历史记录，在Git中，我们用git log命令查看：

$ git log

commit 1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master)

Author: Michael Liao <askxuefeng@gmail.com>

Date:  Fri May 18 21:06:15 2018 +0800

 

  append GPL

 

commit e475afc93c209a690c39c13a46716e8fa000c366

Author: Michael Liao <askxuefeng@gmail.com>

Date:  Fri May 18 21:03:36 2018 +0800

 

  add distributed

 

commit eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0

Author: Michael Liao <askxuefeng@gmail.com>

Date:  Fri May 18 20:59:18 2018 +0800

 

  wrote a readme file

git log命令显示从最近到最远的提交日志

Git必须知道当前版本是哪个版本，在Git中，用HEAD表示当前版本，也就是最新的提交1094adb...（注意我的提交ID和你的肯定不一样），上一个版本就是HEAD^，上上一个版本就是HEAD^^，当然往上100个版本写100个^比较容易数不过来，所以写成HEAD~100。

在Git中，总是有后悔药可以吃的。当你用$ git reset --hard HEAD^回退到add distributed版本时，再想恢复到append GPL，就必须找到append GPL的commit id。Git提供了一个命令git reflog用来记录你的每一次命令：

5.工作区和暂存区

![img](file:///C:\Users\Administrator\AppData\Local\Temp\ksohtml\wps7EAF.tmp.jpg) 

![img](file:///C:\Users\Administrator\AppData\Local\Temp\ksohtml\wps7EB0.tmp.jpg) 

6.撤销修改

Git会告诉你，git checkout -- file可以丢弃工作区的修改：

$ git checkout -- readme.txt

命令git checkout -- readme.txt意思就是，把readme.txt文件在工作区的修改全部撤销，这里有两种情况：

一种是readme.txt自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

一种是readme.txt已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

总之，就是让这个文件回到最近一次git commit或git add时的状态。

Git同样告诉我们，用命令git reset HEAD <file>可以把暂存区的修改撤销掉（unstage），重新放回工作区：

$ git re***\*set\**** HEAD readme.txt

Unstaged changes after reset:

M	readme.txt

git reset命令既可以回退版本，也可以把暂存区的修改回退到工作区。当我们用HEAD时，表示最新的版本。

7.删除文件

用rm命令删了：

$ rm test.txt

你有两个选择，一是确实要从版本库中删除该文件，那就用命令git rm删掉，并且git commit：

$ git rm test.txt

rm 'test.txt'

 

$ git ***\*commit\**** -m "remove test.txt"

[master d46f35e] remove test.txt

 1 file changed, 1 deletion(-)

 ***\*delete\**** mode 100644 test.txt

现在，文件就从版本库中被删除了。

另一种情况是删错了，因为版本库里还有呢，所以可以很轻松地把误删的文件恢复到最新版本：

$ git checkout -- test.txt

git checkout其实是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”。

8.远程库

把本地库的内容推送到远程，用git push命令，实际上是把当前分支master推送到远程。

![img](file:///C:\Users\Administrator\AppData\Local\Temp\ksohtml\wps7EB1.tmp.jpg) 

![img](file:///C:\Users\Administrator\AppData\Local\Temp\ksohtml\wps7EB2.tmp.jpg) 

9.从远程库克隆

![img](file:///C:\Users\Administrator\AppData\Local\Temp\ksohtml\wps7EB3.tmp.jpg) 

$ git clone
