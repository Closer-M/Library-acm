#ifndef STACK_H 
#define STACK_H 
template<typename T>
class Stack
{
public:
	Stack();
	T first();
	T pop();
	bool empty();
	int getSize();
	void push(T value);
	bool contains(T individual);
private:
	T elements[100];
	int size;
};

template<typename T>
Stack<T>::Stack()//默认 size 为 0
{
	size = 0;
}
template<typename T>
bool Stack<T>::empty()//判断 Stack 中是否为空
{
	return (size == 0);
}
template<typename T>
void Stack<T>::push(T value)//加栈中压入一个元素，然后将 size 增加 1
{
	elements[size++] = value;
}
template<typename T>
T Stack<T>::first()//返回 Stack 的栈顶元素
{
	return elements[size - 1];
}
template<typename T>
T Stack<T>::pop()//将栈顶元素压出，方法：直接将 size 减小 1
{
	return elements[--size];
}
template<typename T>
int Stack<T>::getSize()//返回栈中的元素个数
{
	return size;
}
template<typename T>
bool Stack<T>::contains(T individual)
{
	for (int i = 0; i < size; i++)
	{
		if (individual == elements[i])
		{
			return 1;
		}
	}
	return 0;
}
#endif