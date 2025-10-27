#include <iostream>
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
		int child = index-1;
		int parent = (child - 1) / 2;

		while(child > 0)
		{
			if (container[parent] < container[child])
			{
				std::swap(container[parent], container[child]);
			}
			child = parent;
			parent = (child - 1) / 2;
		}

	}

	~PriorityQueue()
	{

	}

	const T & top()
	{
		if(index==0)
		{
			exit(1);
		}
		else
		{
			return container[0];
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

	cout<<priqueue.top();
	return 0;
}