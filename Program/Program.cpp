#include <iostream>


template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

    int size;
public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;

    }
};





int main()
{

    List<int> List;
    return 0;
}
