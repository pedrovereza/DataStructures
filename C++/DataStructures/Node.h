template<class T>
class Node {

private:
	Node<T> *next;

public:
	T Data;

	Node (const T data) : Data(data) {
		Data = data;
		next = nullptr;
	}

	void SetNext(Node<T>* node){
		next = node;
	}
	
	Node<T>* GetNext(){
		return next;
	}
};
