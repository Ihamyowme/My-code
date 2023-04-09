#include <iostream>

using namespace std;




template<class T>
class List
{
public:
	List();
	~List();

	void push_front(T data);
	void pop_front();
	void push_back(T data);
	void pop_back();
	void insert(T data, int index);
	void removeAt(int index);
	void clear();
	int GetSize() { return Size; }

	T& operator[](const int index);

private:
	template<class T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};


template<class T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<class T>
List<T>::~List()
{
	clear();
}


template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;

}


template<class T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;
	delete temp;

	Size--;
}


template<class T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}


template<class T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}


template<class T>
void List<T>::insert(T data, int index)
{
	if (index==0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}


template<class T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	
	else
	{
		Node<T>* previous = this->head;
		
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
			
		}
		
		Node<T>* temp = previous;

		previous = previous->pNext;

		temp->pNext = previous->pNext;

		delete previous;
		

		Size--;
	}
}


template<class T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<class T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

