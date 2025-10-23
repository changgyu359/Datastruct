#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:

    int count;
    int capacity;
    T* pointer;
public:
    Vector()
    {
        count = 0;
        capacity = 0;
        pointer = nullptr;


    }

    void resize(int newsize)
    {
        //1. 새로운 size값 저장
        capacity = newsize;
        //2,3.포인터 변수 생성 및 값 초기화
        T* temporary = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }
        //4.기존 배열값 복사후 새로운 배열에 추가
        for (int i = 0; i < count; i++)
        {
            temporary[i] = pointer[i];
        }

        //5. 기존 배열 메모리 해제
        delete[] pointer;
        //6.기존 배열의 포인터 변수를 새로운 포인터로 변경
        pointer = temporary;

    }
    void push_back(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (capacity <= count)
        {

            resize(capacity * 2);

        }
        pointer[count++] = data;
    }
    void pop_back()
    {
        if (count <= 0)
        {
            cout << "Vector is empty" << endl;
        }
        else
        {
            pointer[--count] = NULL;
        }
    }

    const int& size()
    {
        return count;
    }

    const T& operator[] (const int& index)
    {
        return pointer[index];
    }

    ~Vector()
    {
        delete[] pointer;
    }
};


int main()
{
    Vector<int> vector;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);
    vector.push_back(50);

    vector.pop_back();

    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << endl;
    }


    return 0;
}
