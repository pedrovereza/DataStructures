#include "Node.h"

template<class T>
class BasicNodeStructure
{
	
protected:
	Node<T>* root;

	BasicNodeStructure(){
		root = nullptr;
	}

	~BasicNodeStructure(){
		DeleteNodes(root);
	}

	void DeleteNodes(Node<T>* node)
	{
		while (node != nullptr)
		{
			Node<T>* temp = node;
			node = node->GetNext();
			delete temp;
		}
	}

public:
	bool IsEmpty(){
		return root == nullptr;
	}

	void Clear()
	{
		DeleteNodes(root);
		root = nullptr;
	}

	size_t Count()
	{
		size_t count = 0;
		Node<T>* iterator = root;

		while(iterator != nullptr)
		{
			count++;

			iterator = iterator->GetNext();
		}

		return count;
	}
};