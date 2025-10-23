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

        for (int i = 0; i < highset + 1; i++)
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
        else if (capacity - 1 <= highset)
        {
            resize(capacity * 2);
        }
        container[++highset] = data;
    }

    const T& top()
    {

        return container[highset];


    }

    const int& size()
    {
        return highset + 1;
    }
    const bool& empty()
    {
        return (highset <= -1);
    }

    void pop()
    {
        if (empty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            container[highset--] = NULL;
        }
    }

    ~Stack()
    {
        if (container != nullptr)
        {
            delete[] container;
        }

    }

};

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);


    while (stack.empty() == false)
    {
        cout << stack.top() << endl;

        stack.pop();
    }

    cout << "Stack Size:" << stack.size() << endl;
    return 0;
}