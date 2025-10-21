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

    void resize(int newSize)
    {
        capacity = newsize;
        //1. 새로운 size값 저장
        T* newpointer = new T;
        //2,3.포인터 변수 생성 및 값 초기화
        //몷루....
        //4.기존 배열값 복사후 새로운 배열에 추가
        T* temporary = pointer;
            delete temporary;
        //5. 기존 배열 메모리 해제
        pointer = newpointer;
        //6.기존 배열의 포인터 변수를 새로운 포인터로 변경
        
        
    }
};


int main()
{
    Vector<int> vector;

    return 0;
}
