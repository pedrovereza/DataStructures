#include "BasicNodeStructure.h"

template<class T>
class Stack : public BasicNodeStructure<T>{

public:
	Stack(){
	}

	~Stack(){
	}

	void Push(T data)
	{
		Node<T>* newRoot = new Node<T>(data);

		if (!IsEmpty())
			newRoot->SetNext(root);

		root = newRoot;
	}

	T* Pop()
	{
		if (IsEmpty())
			return nullptr;

		T* value = new T(root->Data);

		Node<T>* temp = root;
		root = temp->GetNext();
		delete temp;

		return value;
	}

	T* Peek()
	{
		return &root->Data;
	}
};