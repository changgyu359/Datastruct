#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
    int highset;
    int capacity;
    T* container;
public:
    Stack()
    {
        highset = -1;
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

        for (int i = 0; i < count; i++)
        {
            temporary[i] = container[i];
        }


        delete[] container;

        container = temporary;

    }
    void push(T data)
    {
        if (capacity - 1 <= highset)
        {
            capacity++;
        }
        container[highset++] = data;
    }
};

int main()
{
   
    return 0;
}