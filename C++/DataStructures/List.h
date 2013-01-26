#include "BasicNodeStructure.h"

template<class T>
class List : public BasicNodeStructure<T>{

private:
	
	Node<T>* LastNode()
	{
		return GetNodeAt(Count() - 1);
	}

	Node<T>* GetNodeAt(const int index)
	{
		int indexOf = 0;

		Node<T>* iterator = root;

		while(iterator != nullptr)
		{
			if (indexOf != index)
			{
				iterator = iterator->GetNext();
				indexOf++;
			}
			else
				return iterator;
		}

		return nullptr;
	}

	void Add(Node<T>* node)
	{
		if (IsEmpty())
			root = node;
		else
			LastNode()->SetNext(node);
	}

public:
	List() : BasicNodeStructure<T>()
	{
	}

	~List()
	{
	}

	void Add(T data)
	{
		Add(new Node<T>(data));
	}

	T* FirstOrDefault()
	{
<<<<<<< HEAD
		return IsEmpty() ? new T() : &root->Data;
=======
		//TODO: this isn't a good way to deal with the possibility of this being
		// empty.  When you call this method on an empty list, you'll have to
		// delete what was returned or you'll have a memory leak.  OTOH, if you
		// delete the return value when it's not an empty list, you have a bug.
		// I suggest you rename this method First and throw an exception when
		// the list is empty.

		return root == nullptr ? new T() : &root->Data;
>>>>>>> 5d8d6c7afa1c5ca5e40e36b4cad588aa869a48e3
	}

	T* Last()
	{
		return GetAt(Count() -1);
	}

	T* GetAt(const int index)
	{
		Node<T>* node = GetNodeAt(index);

		if (node != nullptr)
			return &node->Data;

		return nullptr;
	}

	bool Contains(T value)
	{
		Node<T>* iterator = root;

		while(iterator != nullptr)
		{
			if (iterator->Data == value)
				return true;

			iterator = iterator->GetNext();
		}

		return false;
	}

	void RemoveAt(int index)
	{
		//TODO: throw exception if index is equal to or higher than Count()

		int indexOf = 0;

		Node<T>* previous = nullptr;
		Node<T>* iterator = root;

		while(iterator != nullptr)
		{
			if (indexOf != index)
			{
				previous = iterator;
				iterator = iterator->GetNext();
				indexOf++;
			}
			else
			{
				previous->SetNext(iterator->GetNext());
				iterator = nullptr;
				break;
			}
		}
	}
};
