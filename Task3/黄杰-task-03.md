# 问题
## vector与数组的区别
vector是一种模板类封装的动态数组，是用new创建动态数组的替代品。

就**存储区域**而言，数组将数据存储于栈中；而vector将数据存储于另一个区域中（通常为堆或者自由存储区）。就**存储方式**而言，vector自带动态存储功能，它用new和delete自动管理内存（vector会自动回收数据），它的长度可以是变量也可以是常数，并且它可以根据后续添加的数据自动适应长度；数组是静态数组，定义时它的长度只支持常量而无法用变量，确定数组长度之后无法更改。

此外，vector还是一个重载运算符，它既表示一种数组存储方式，也表示一种数据类型，即**矢量**。

总体而言，vector更加的安全与便利，但对于内存运用效率稍有降低。数组的运用效率较高，但是不是特别的安全与方便。

## 编程：利用两个队列来实现一个栈

```c++

struct Queue {
	int a[20];
	int head, tail;//head代表第一个元素的下标，tail代表将要插入元素的下标 
};
void enqueue(struct Queue* q, int node) {
	if ((q->tail + 1) % 20 == q->head) {
		printf("Queue has no room!\n");
		return;
	}
	q->tail = (q->tail + 1) % 20;
	q->a[q->tail] = node;
}
int dequeue(struct Queue* q) {
	if (q->head == q->tail) {
		printf("Queue has no node!\n");
		return -1;
	}
	q->head = (q->head + 1) % 20;
	return q->a[q->head];
}

int pop(struct Queue* q1, struct Queue* q2) {
	while ((q1->head + 1) % 20 < q1->tail) {
		int n = dequeue(q1);
		enqueue(q2, n);
	}
	int n = dequeue(q1);
	return n;
————————————————
版权声明：本文为CSDN博主「爱写bug的疼老师」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/sinat_32092165/article/details/105194876
```



# 学习笔记

## 栈

栈（stack）是只允许在一端进行插入或删除的线性表。首先栈是线性表，但限定这种线性表只能在某一端进行插入和删除操作。

**栈顶**（top）：线性表语序进行插入删除的一端。

**栈底**（bottom）：固定的，不允许进行插入和删除的另一端。

**空栈**：不含任何元素的空表。

**LIFO**（last in first out）：先进后出的结构，栈就是典型的先进后出的线性表，位于栈顶的是最后入栈的元素，而位于栈底的是最开始入栈的元素。

栈可以有很多种类型，除了单一方向的栈之外，还有**共享栈**，即两端都为栈顶，而中间两栈连接的位置成为栈底。也有**链栈**，是基于链表结构的栈类型。

常见栈的操作有：

**初始化**

```c++
void InitStack(SqStack *S){
    S->top = -1;    //初始化栈顶指针
}
```

**判断栈是否为空**

```c++
bool StackEmpty(SqStack S){
    if(S.top == -1){    
        return true;    //栈空
    }else{  
        return false;   //不空
    }
}
```

**进栈（push）**		添加栈中元素

```c++
/*插入元素e为新的栈顶元素*/
Status Push(SqStack *S, ElemType e){
    //满栈
    if(S->top == MAXSIZE-1){
        return ERROR;
    }
    S->top++;   //栈顶指针增加一
    S->data[S->top] = e;    //将新插入元素赋值给栈顶空间
    return OK;
}
```

**出栈(pop)**			删除栈中的元素

```c++
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
Status Pop(SqStack *S, ElemType *e){
    if(S->top == -1){
        return ERROR;
    }
    *e = S->data[S->top];   //将要删除的栈顶元素赋值给e
    S->top--;   //栈顶指针减一
    return OK;
}
```

**读取栈顶元素（GetTop）**

```c++
/*读栈顶元素*/
Status GetTop(SqStack S, ElemType *e){
    if(S->top == -1){   //栈空
        return ERROR;
    }
    *e = S->data[S->top];   //记录栈顶元素
    return OK;
}
```



## 队列

队列（queue）与栈相似，只允许一端进行插入操作，而另一端进行删除操作的线性表。不同于栈的是，队列只允许先进先出（First In First Out）**FIFO**，允许插入的一端为**队尾**，允许删除一端为**队头**。

常见的基本操作有：

**InitQueue(&Q)**：初始化队列，构造一个空队列Q。
**QueueEmpty(Q)**：判队列空，若队列Q为空返回true，否则返回false。
**EnQueue(&Q, x)**：入队，若队列Q未满，将x加入，使之成为新的队尾。
**DeQueue(&Q, &x)**：出队，若队列Q非空，删除队头元素，并用x返回。
**GetHead(Q, &x)**：读队头元素，若队列Q非空，则将队头元素赋值给x。

一般按照顺序进行存储的队列容易使得队列发生假溢出

所以队列通常按照循环队列进行存储。

