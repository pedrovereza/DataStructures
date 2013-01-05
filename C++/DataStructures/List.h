#include "Node.h"

template<class T>
class List{

private:
	Node<T>* root;
	int count;

	void DeleteNodes(Node<T>* node)
	{
		while (node != nullptr)
		{
			Node<T>* temp = node;
			node = node->GetNext();
			delete temp;
		}
	}

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
		if (root == nullptr)
			root = node;
		else
			LastNode()->SetNext(node);

		count++;
	}

	void Initialize()
	{
		root = nullptr;
		count = 0;
	}

public:
	List()
	{
		Initialize();
	}

	~List()
	{
		DeleteNodes(root);
	}

	void Add(T data)
	{
		Add(new Node<T>(data));
	}

	T FirstOrDefault()
	{
		return root == nullptr ? T() : root->Data;
	}

	T Last()
	{
		return GetAt(Count() -1);
	}

	T GetAt(const int index)
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
				return iterator->Data;
		}

		return NULL;
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

	void Clear()
	{
		DeleteNodes(root);
		Initialize();
	}

	int Count()
	{
		return count;
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
				count--;
				iterator = nullptr;
				break;
			}
		}
	}
};