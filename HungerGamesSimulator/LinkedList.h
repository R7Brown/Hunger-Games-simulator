#pragma once
#ifndef _LINKEDLIST_H_
template <class T>
class LinkedList
{
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
		first->element = NULL;
		last->previous = first;
		last->element = NULL;
	}

	~LinkedList<T>()
	{
		Node<T> * iter = first;
		Node<T> * del = first;

			while (iter->next != nullptr)
			{
				iter->next = iter->next;
				del->previous = del->next = nullptr;
				del->element = NULL;
				delete del;
				del = iter;
			}

		iter->next = del->next = iter->previous = del->previous = nullptr;
		iter->element = del->element = NULL;
		delete first;
		delete last;
		first = last = nullptr;
	}

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

	void remove(int index)
	{
		Node<T> * iter = first;
		Node<T> * del = iter;
		if (index < size)
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
				del->element = NULL;
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
				del->element = NULL;
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
				del->element = NULL;
				delete del, iter;
				del = iter = nullptr;
				size--;
			}
		}
		else
		{
			cerr << "ERROR: attepting to delete out of bounds index in linked list.\n\n";
		}
		iter = del = nullptr;
	}

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

	T operator [] (int& index)
	{
		return getElement(index);
	}
};

#endif // !_LINKEDLIST_H_
