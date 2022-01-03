# 常凯文
# vector与数组有哪些区别
* vector 具有动态内存变化的机制
* vector 支持多种操作如v.empty(),v.push_back()等等
* vector 除下标访问以为，还可以使用front和back以及at访问方式，使得访问更加安全
*  等等
# 两个队列实现一个栈
~~~
#ifndef STACK_H
#define STACK_H

#include<queue>
#include<iostream>

template<typename T>
class Stack{
private:
    std::queue<T> q1;
    std::queue<T> q2;
    bool q1_used;
    bool q2_used;
public:
    Stack();
    void push(T elem);
    void pop();
    T top() const;
    bool empty() const;
    int size() const;
};
template<typename T>
Stack<T>::Stack(){
    q1_used=true;
    q2_used=false;
}
template<typename T>
void Stack<T>::push(T elem){
    if(q1_used) q1.push();
    if(q2_used) q2.push();
}
template<typename T>
void Stack<T>::pop(){
    if(q1_used&&!q1.empty()){
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        q1_used=false;
        q2_used=true;
        return ;
    }
   if(q2_used&&!q2.empty()){
        while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
        q2_used=false;
        q1_used=true;
        return ;
    }
}
template<typename T>
bool Stack<T>::empty() const{
    return (q1_used&&q1.empty())||(q2_used&&q2.empty())
}
template<typename T>
int Stack<T>::size() const{
    if(q1_used) return q1.size();
    if(q2_used) return q2.size();
}
template<typename T>
T Stack<T>::top() const{
    if(q1_used) return q1.back();
    if(q2_used) return q2.back();
}
#endif
~~~
# 坦克大战
自制的坦克大战在教程的基础上主要加入MOBA元素，赋予坦克技能释放的机制，除去普通攻击外共有四个技能。具体介绍在游戏开始界面“说明”之中。
