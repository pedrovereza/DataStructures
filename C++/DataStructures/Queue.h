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
		if (IsEmpty())
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
		if (IsEmpty())
			return nullptr;

		T* value = new T(root->Data);

		Node<T>* temp = root;
		root = root->GetNext();
		delete temp;

		return value;
	}

	T* Peek()
	{
		return (&root->Data);
	}
};