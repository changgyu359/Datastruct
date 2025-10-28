﻿#include <iostream>
#define SIZE 4

using namespace std;

template <typename T>
class PriorityQueue
{
private:
	int index;
	int capacity;
	T* container;
public:
	PriorityQueue()
	{
		index = 0;
		capacity = 0;
		container = nullptr;
	}

	void resize(int newsize)
	{
		capacity = newsize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}


		delete[] container;

		container = temporary;

	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (capacity <= index)
		{

			resize(capacity * 2);

		}
		container[index++] = data;
		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				std::swap(container[parent], container[child]);
			}
			child = parent;
			parent = (child - 1) / 2;
		}

	}

	const bool& empty()
	{
		return index <= 0;
	}

	const int& size()
	{
		return size;
	}





	const T& top()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return container[0];
		}
	}

	~PriorityQueue()
	{
		delete[] container;
	}

	void pop()
	{
		if (index <= 0)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			container[0] = container[--index];
			container[index] = NULL;


			int parent = 0;
			int child = parent * 2 + 1;

			while (child < index)
			{
				child = parent * 2 + 1;

				if (container[child] < container[child + 1])
				{
					child++;
				}

				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					std::swap(container[child], container[parent]);

					parent = child;
				}
			}
		}



	}
};

int main()
{
	PriorityQueue<int> priqueue;

	priqueue.push(10);
	priqueue.push(20);
	priqueue.push(5);
	priqueue.push(33);

	cout << priqueue.top() << endl;

	while (priqueue.empty() == false)
	{
		cout << priqueue.top() << endl;

		priqueue.pop();
	}
	return 0;
}