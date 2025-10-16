#include <iostream>



template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
    };



    int size;

    Node* head;

public:
    List()
    {
        size = 0;
        head = nullptr;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;

            newNode->next = nullptr;
        }

        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;

    }
    void pop_front()
    {
        if (size <= 0)
        {
            std::cout << "Linked List is Empty" << std::endl;
        }
        else
        {
            Node* deleteNode = head;

            head = deleteNode->next;

            delete deleteNode;

            size--;
        }
    }
    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;


        }

        else
        {
            Node* currentNode = head;
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;

        }
        size++;


    }
    void pop_back()
    {
        if (size <= 0)
        {
            std::cout << "Linked List is Empty" << std::endl;
        }
        else
        {
            Node* deleteNode = head;
            Node* preNode = nullptr;

            if (size == 1)
            {
                head = deleteNode->next;

                delete deleteNode;
            }
            else
            {
                while (deleteNode->next != nullptr)
                {
                    preNode = deleteNode;
                    deleteNode = deleteNode->next;

                }
                preNode->next = deleteNode->next;
                delete deleteNode;

            }



            size--;
        }
    }
    ~List()
    {

        while (head != nullptr)
        {
            pop_front();
        }
    }
    const bool empty()
    {
        return (head == nullptr);
    }
};





int main()
{
    List<int> list;

    list.push_front(10);
    list.push_front(5);
    list.pop_front();
    list.pop_front();

    list.push_back(20);
    list.push_back(30);

    list.pop_back();
    list.pop_back();
    list.pop_back();

    return 0;
}
