template<typename T> class Stack
{
public:
	Stack(void);
	~Stack(void);
 
	void appendTail(const T& node);
	T deleteHead();
 
private:
	queue<T> q1;
	queue<T> q2;
};
 
template<typename T>
void Stack<T>::appendTail(const T& node)//实现栈元素的插入
{
	//数据的插入原则：保持一个队列为空，一个队列不为空，往不为空的队列中插入元素
	if (!q1.empty())
	{
		q1.push(node);
	}
	else
	{
		q2.push(node);
	}
}
 
template<typename T>
T Stack<T>::deleteHead()//实现栈元素的删除
{
	int ret = 0;
	if (!q1.empty())
	{
		int num = q1.size();
		while (num > 1)
		{
			q2.push(q1.front());
			q1.pop();
			--num;
		}
		ret = q1.front();
		q1.pop();
	}
	else
	{
		int num = q2.size();
		while (num > 1)
		{
			q1.push(q2.front());
			q2.pop();
			--num;
		}
		ret = q2.front();
		q2.pop();
	}
	return ret;
}