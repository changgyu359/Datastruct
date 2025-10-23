#include <iostream>
#define SIZE 5

using namespace std;

template <typename T>
class Queue
{
private:
	int rear;
	int front;
	T container[SIZE];

public:
	Queue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void push(T data)
	{
		if (frpmt == 0 && rear == 5)
		{
			cout << "Queue overflow" << endl;
		}
		else
		{
			for (int i = front; i < rear; i++)
			{
				container[i - 1] = container[i];
			}
		}
	}
};

int main()
{
  
	Queue<int> queue;

	return 0;
}