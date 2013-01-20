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

		if (root != nullptr)
			newRoot->SetNext(root);

		root = newRoot;
	}

	T* Pop()
	{
		if (IsEmpty())
			return nullptr;

		//TODO: You never get to delete the previous root.
		Node<T>* ret = root;
		root = root->GetNext();

		return &ret->Data;
	}

	T* Peek()
	{
		return &root->Data;
	}
};
