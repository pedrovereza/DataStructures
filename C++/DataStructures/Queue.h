#include "BasicNodeStructure.h"

template<class T>
class Queue : public BasicNodeStructure<T>
{
public:
	Queue()
	{
	}

	~Queue()
	{
	}

	void Enqueue(const T data)
	{
		if (root == nullptr)
		{
			root = new Node<T>(data);
			return;
		}

		Node<T>* iterator = root;

		while(iterator->GetNext() != nullptr)
			iterator = iterator->GetNext();

		iterator->SetNext(new Node<T>(data));
	}

	T* Dequeue()
	{
		if (root == nullptr)
			return nullptr;

		Node<T>* temp = root;
		root = root->GetNext();

		return &(temp->Data);
	}

	T* Peek()
	{
		return (&root->Data);
	}
};