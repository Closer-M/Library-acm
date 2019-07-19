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
Stack<T>::Stack()//Ĭ�� size Ϊ 0
{
	size = 0;
}
template<typename T>
bool Stack<T>::empty()//�ж� Stack ���Ƿ�Ϊ��
{
	return (size == 0);
}
template<typename T>
void Stack<T>::push(T value)//��ջ��ѹ��һ��Ԫ�أ�Ȼ�� size ���� 1
{
	elements[size++] = value;
}
template<typename T>
T Stack<T>::first()//���� Stack ��ջ��Ԫ��
{
	return elements[size - 1];
}
template<typename T>
T Stack<T>::pop()//��ջ��Ԫ��ѹ����������ֱ�ӽ� size ��С 1
{
	return elements[--size];
}
template<typename T>
int Stack<T>::getSize()//����ջ�е�Ԫ�ظ���
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