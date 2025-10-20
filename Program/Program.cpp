#include <iostream>

using namespace std;

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
    void push_back(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;

        }
        size++;
    }
    void push_front(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;
            head->next = newNode;
        }
        size++;

        
    }
    void pop_front()
    {
       
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            Node* delNode = head->next;
            if (head == delNode)
            {
                head = nullptr;
            }
            else
            {
                head->next = delNode->next;
            }
            delete delNode;
        }
        size--;
    }
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            Node* delNode = head;
            if (size == 1)
            {
                head = nullptr;
            }
            else
            {
               
            }
            delete delNode;
        }
    }
};


int main()
{
    List<int> List;

    List.push_back(10);
    List.push_back(20);
    List.push_back(30);

    List.push_front(5);

    List.pop_front();
    List.pop_front();
    List.pop_front();
    List.pop_front();
    List.pop_front();

    return 0;
}
