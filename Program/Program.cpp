#include <iostream>


using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
	int size;
	int capacity;

	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket* bucket;
public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket[capacity];


		for (int i = 0; i < capacity; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}

	template<typename KEY>
	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % capacity;
	}

	template <>
	unsigned int hash_function(const char* key)
	{
		int sum = 0;
		const char* pointer = key;

		for (int i = 0; *key != '\0';i++)
		{
			sum += key[i];

			key++;
		}
		return (unsigned int)sum % capacity;
	}

	void insert(KEY key, VALUE value)
	{
		
		//해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = hash_function(key);

		//새로운 노드 생성
		Node* newnode = new Node;
		newnode->key = key;
		newnode->value = value;

		newnode->next = nullptr;

		//노드가 1개라도 존재하지 않는다면

		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newnode;
		}
		else
		{
			newnode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newnode;
		}
		
		
		size++;
		bucket[hashIndex].count++;

	}

	void erase(KEY key)
	{
		//1.해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = hash_function(key);

		//2.Node를 탐색할 수 있는 포인터 변수 선언
		Node* currentnode = bucket[hashIndex].head ;

		//3.이전 Node를 저장할 수 있는 포인터 변수 선언
		Node* prenode = nullptr;

		//4.currentnode가 nullptr과 같다면 함수를 종료
		if (currentnode==nullptr)
		{
			cout << "not key found..." << endl;
		}
		else
		{
			//5.currentnode를 이용해서 내가 찾고자 하는 key값을 찾기
			
			while (currentnode!=nullptr)
			{
				if (currentnode->key == key)
				{
					if (currentnode == bucket[hashIndex].head)
					{
						bucket[hashIndex].head = currentnode->next;
					}
					else
					{
						prenode->next = currentnode->next;
					}

					size--;

					bucket[hashIndex].count--;

					delete currentnode;

					return;
				}
				else
				{
					prenode = currentnode;
					currentnode = currentnode->next;
				}
				
			}

			cout << "not key found..." << endl;
		}
	}

	const float& load_factor()
	{
		return (float)size / capacity;
	}

	const int& bucket_count()
	{
		return capacity;
	}

	~HashTable()
	{

	}
};

int main()
{
	HashTable<const char*, int> hashtable;

	hashtable.insert("심연의 가면", 3000);
	hashtable.insert("바미의 불씨", 1000);
	hashtable.insert("사슬갑옷", 800);

	hashtable.erase("심연의 가면");
	hashtable.erase("돌풍");
	
	cout << hashtable.load_factor() << endl;
	cout << hashtable.bucket_count() << endl;

	return 0;
}