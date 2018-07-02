#pragma once
#ifndef _LINKEDLIST_H_


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////       This Linked List class is extremely limited as it was created specifically for this project.       ////
//// For most other work it will most likely need to be expanded, or the use of another library may be better ////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
class LinkedList
{
	//Linked list node
	template <class T>
	class Node
	{
	public:
		Node<T> * previous;
		Node<T> * next;
		T element;
	};
public:
	Node<T> * first = new Node<T>;
	Node<T> * last = new Node<T>;
	int size = 0;

	LinkedList<T>()
	{
		first->next = last;
		last->previous = first;
	}

	~LinkedList<T>()
	{
		Node<T> * iter = first;
		Node<T> * del = first;

			while (iter->next != nullptr)
			{
				iter->next = iter->next;
				del->previous = del->next = nullptr;
				delete del;
				del = iter;
			}

		iter->next = del->next = iter->previous = del->previous = nullptr;
		delete iter, del, first, last;
		iter = del = first = last = nullptr;
	}

	//Inserts element into the tail of the list
	void insert(T in)
	{
		if (size == 0)
		{
			first->element = in;
			size++;
		}
		else if (size == 1)
		{
			last->element = in;
			size++;
		}
		else
		{
			Node<T> * one = new Node<T>;
			last->next = one;
			one->next = nullptr;
			one->previous = last;
			last = one;
			last->element = in;
			size++;
			one = nullptr;
		}
	}

	//inserts element into any index of the list. Only indexes able to be inserted
	//into are ones that already exist in the list.
	void insert(int index, T in)
	{
		Node<T> * iter = first;
		Node<T> * one = new Node<T>;
		if (index < size)
		{
			if (index == 0)
			{
				first = one;
				iter->previous = one;
				one->next = iter;
				one->element = in;
				size++;
			}
			else
			{
				for (int i = 0; i < index; i++)
				{
					iter = iter->next;
				}
				one->previous = iter->previous;
				one->next = iter;
				iter->previous->next = iter->previous = one;
				one->element = in;
				size++;
			}
		}
		else
		{
			cerr << "ERROR attempting to insert element beyond current linked list size.\n\n"
		}
		iter = one = nullptr;
	}

	//Ensures that a particular element exists in the list
	bool exists(T in)
	{
		Node<T> iter = first;

		for (int i = 0; i < size; i++)
		{
			if (iter->element == in)
			{
				iter = nullptr;
				return true;
			}
			iter = iter->next;
		}
		iter = nullptr;
		return false;
	}

	//Removes element from specific index of the list.
	void remove(int index)
	{
		Node<T> * iter = first;
		Node<T> * del = iter;
		if (index < size && index >= 0)
		{
			if (size == 2)
			{
				if (index == 0)
				{
					first->element = last->element;
					delete last;
					last = new Node<T>;
					last->previous = first;
					first->next = last;
					size--;
				}
				else if (index == 1)
				{
					delete last;
					last = new Node<T>;
					last->previous = first;
					first->next = last;
					size--;
				}
			}
			else if (size == 1)
			{
				delete first;
				first = new Node<T>;
				first->next = last;
				last->previous = first;
				size--;
			}
			else if (index == 0)
			{
				iter = iter->next;
				first = iter;
				iter->previous = nullptr;
				del->next = del->previous = nullptr;
				delete del;
				del = nullptr;
				size--;
			}
			else if (index == size - 1)
			{
				del = last;
				iter = last = last->previous;
				iter->next = nullptr;
				del->next = del->previous = nullptr;
				delete del;
				del = iter = nullptr;
				size--;
			}
			else
			{
				for (int i = 0; i < index; i++)
				{
					iter = iter->next;
				}

				del = iter;
				iter->next->previous = iter->previous;
				iter->previous->next = iter->next;
				del->next = del->previous = nullptr;
				delete del, iter;
				del = iter = nullptr;
				size--;
			}
		}
		else
		{
			cerr << "ERROR: attepting to delete out of bounds index in linked list.\n\n";
			exit(1);
		}
		iter = del = nullptr;
	}

	//removes a certain element from the list as specified.
	//TODO: create different function instead of just overloading the remove function
	//This works but is somewhat confusing.
	void remove(bool over,T rem)
	{
		roster[0].ID;
		Node<T> * iter = first;
		int index = 0;

		try
		{
			while (iter->element != rem)
			{
				iter = iter->next;
				index++;
			}
		}
		catch (const std::exception&)
		{
			cerr << "ERROR: attempting to delete an element that does not exist.\n\n";
			index = -1;
		}
		remove(index);
	}

	//Empties list back to size 0
	void emptylist()
	{
		for (int i = 0; i < size; i++)
		{
			remove(0);
		}
	}

	//gets element at a certain index of the list.
	T getElement(int index)
	{
		Node<T> * iter = first;
		T value;
		for (int i = 0; i < index; i++)
		{
			iter = iter->next;
		}
		value = iter->element;
		iter = nullptr;
		return value;
	}

	//bracket operator allows the list to be read like an array.
	//This only works for reads, not writes to the list.
	T operator [] (int& index)
	{
		return getElement(index);
	}
};

#endif // !_LINKEDLIST_H_
