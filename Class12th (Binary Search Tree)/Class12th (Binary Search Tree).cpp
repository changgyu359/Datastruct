#include <iostream>


using namespace std;

template<typename T>
class Set
{
private:

	struct Node
	{
		T data;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(T data)
		{
			this->data = data;
		}
	};

	Node* root;

public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		Node* newNode = new Node(data);

		if (root == nullptr)
		{
			root = newNode;
		}
		else
		{
			Node* currentNode = root;


			while (currentNode != nullptr)
			{
				if (currentNode->data == data)
				{
					cout << "이미 존재하는 데이터 값입니다!" << endl;
					delete newNode;

					return;
				}
				else if (currentNode->data > data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = newNode;

						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = newNode;

						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}

			}


		}
	}

	void release(Node* root)
	{
		if (root != nullptr)
		{
			release(root->left);

			release(root->right);

			delete root;
		}
	}

	~Set()
	{
		release(root);
	}

	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentNode = nullptr;

		while (currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if (data < currentNode->data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		if (currentNode == nullptr)
		{
			cout << "the data does not exist" << endl;

		}
		else if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			if (parentNode != nullptr)
			{
				if (data < parentNode->data)
				{
					parentNode->left = nullptr;
				}
				else
				{
					parentNode->right = nullptr;
				}

			}
			else
			{
				root = nullptr;
			}


		}
		else if (currentNode->left == nullptr || currentNode->right == nullptr)
		{

		}
	}
};

int main()
{
	Set<int> set;

	set.insert(10);
	set.insert(17);
	set.insert(15);
	set.insert(20);
	set.insert(16);
	set.insert(10);

	set.erase(10);

	return 0;
}