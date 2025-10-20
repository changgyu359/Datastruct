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
    void push_front(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;

        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;

        }
        size++;
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            std::cout << "Link is empty." << std::endl;
        }
        else
        {
            Node* deleteNode = head;
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                deleteNode->next->prev = nullptr;

                head = head->next;
            }
            delete deleteNode;
            size--;
        }


    }
    void push_back(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;

        }
        size++;
    }
    void pop_back()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty." << std::endl;
        }
        else
        {
            Node* deleteNode = tail;
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail->prev->next = nullptr;
                tail = tail->prev;
            }
            delete deleteNode;
            size--;
        }


    }
    const bool& empty()
    {
        return (head == nullptr);
    }
    ~List()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
};





int main()
{

    List<int> List;

    List.push_front(10);
    List.push_front(5);

    List.push_back(20);
    List.push_back(30);


    List.pop_front();
    List.pop_front();
    List.pop_back();
    List.pop_back();
    List.pop_back();
    return 0;
}
