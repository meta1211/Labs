#include "List.h"

bool List::add(Node *node, int key)
{
	//Exists only for finding exceptions actualy we can use argument node as correct pointer.
	Node *curNode = Find(node);
	if (curNode)
	{
		Node *newNode = new Node(key, curNode, curNode->next);
		curNode->next->prev = newNode;
		curNode->next = newNode;
		size++;
		return true;
	}
	else
	{
		std::cout << "We cant add! Node doesnt exist in this List.\nAdress: " << node << " Key: " << node->GetKey() << '\n';
		return true;
	}
}

bool List::del(Node *node)
{
	//Exists only for finding exceptions actualy we can use argument node as correct pointer.
	Node *curNode = Find(node);;
	if (curNode)
	{
		curNode->prev->next = curNode->next;
		curNode->next->prev = curNode->prev;
		delete curNode;
		size--;
		return true;
	}
	else
	{
		std::cout << "We cant delete! Node doesnt exist in this List.\nAdress: " << node << " Key: " << node->GetKey() << '\n';
		return false;
	}
}

Node *List::Find(Node *node)
{
	Node *curNode = head;
	while (curNode && curNode != node)
	{
		curNode = curNode->next;
	}
	return curNode;
}

void List::recursiveDelete(Node *node)
{
	if (!node->next)
	{
		recursiveDelete(node->next);
	}
	delete node;
}

void List::recursiveDelete(Node *start, Node *end)
{
	if (start->next != end)
	{
		recursiveDelete(start->GetNextNode(), end);
	}
	delete start;
}

Node *List::Find(int key)
{
	Node *curNode = head;
	while (curNode && curNode->key != key)
	{
		curNode = curNode->next;
	}
	return curNode;
}

List::List()
{
	size = 0;
	tail = new Node(0, nullptr, nullptr);
	head = new Node(0, nullptr, tail);
	tail->prev = head;
}

List::List(int size)
{
	this->size = size;
	tail = new Node(0, nullptr, nullptr);
	head = new Node(0, nullptr, tail);
	tail->prev = head;
	std::cout << "Input list please:\n";
	for (int i = 0; i < size; i++)
	{
		int value;
		std::cin >> value;
		AddToHead(value);
	}
}

List::List(List &source)
{
	size = 0;
	tail = new Node(0, nullptr, nullptr);
	head = new Node(0, nullptr, tail);
	tail->prev = head;
	for (int i = 0; i < source.size; i++)
	{
		AddToTail(source[i]);
	}
}

List::~List()
{
	if (size)
	{
		recursiveDelete(head);
	}
}

void List::InputList(int size)
{
	if (size)
		Clear();
	std::cout << "Input list please:\n";
	for (int i = 0; i < size; i++)
	{
		int value;
		std::cin >> value;
		AddToHead(value);
	}
}

void List::PrintList()
{
	if (size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << operator[](i) << ' ';
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << "List is empty.\n";
	}
}

void List::AddToTail(int k)
{
	add(tail->prev, k);
}

void List::DelToTail()
{
	del(tail->prev);
}

void List::AddToHead(int k)
{
	add(head, k);
}

void List::DelToHead()
{
	del(head->next);
}

void List::AddToIndex(int ind, int key)
{
	add(FindKey(operator[](ind)), key);
}

void List::DelToIndex(int ind)
{
	del(FindKey(operator[](ind)));
}

void List::AddToKey(int searchingKey, int key)
{
	add(FindKey(searchingKey), key);
}

void List::DelToKey(int searchingKey)
{
	del(FindKey(searchingKey));
}

void List::Clear()
{
	if (size)
	{
		recursiveDelete(head->next, tail);
		tail->prev = head;
		head->next = tail;
		size = 0;
	}
}

void List::operator=(List &source)
{
	if (this != &source)
	{
		if (size)
			Clear();
		for (int i = 0; i < source.size; i++)
		{
			AddToTail(source[i]);
		}
	}
}

List& List::operator+(List Second)
{
	List *result = new List(*this);
	for (int i = 0; i < Second.size; i++)
	{
		result->AddToTail(Second[i]);
	}
	return *result;
}

void List::operator+=(List Second)
{
	List result(*this + Second);
	*this = result;
}

int & List::operator[](int ind)
{
	if (ind < size)
	{
		int counter = 0;
		for (Node *p = head->next; p->next; p = p->next)
		{
			if (counter == ind)
			{
				return p->key;
			}
			counter++;
		}
	}
	else
	{
		throw std::out_of_range("Out of range!");
	}
}

bool List::Empty()
{
	return size == 0;
}

bool List::operator==(List second)
{
	if(size != second.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (operator[](i) != second[i])
		{
			return false;
		}
	}
	return true;
}

Node * List::FindPosition(int key)
{
	return Find(key);
}

Node * List::Max()
{
	if (!size)
		return nullptr;
	Node *m = head->next;
	for (Node *p = head->next->next; p->next; p = p->next)
	{
		if (m->key < p->key)
		{
			m = p;
		}
	}
	return m;
}

Node * List::Min()
{
	if (!size)
		return nullptr;
	Node *m = head->next;
	for (Node *p = head->next->next; p->next; p = p->next)
	{
		if (m->key > p->key)
		{
			m = p;
		}
	}
	return m;
}

void List::AddToHead(List source)
{
	for (int i = 0; i < source.size; i++)
	{
		AddToHead(source[i]);
	}
}

Node *List::FindKey(int key)
{
	Node *p;
	for (p = head->next; p && p->key != key; p = p->next);
	return p;
}
