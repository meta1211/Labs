#pragma once
#include <iostream>

class Node
{
private:
	int key;
	Node *prev;
	Node *next;
public:
	friend class List;
	Node()
	{
		key = -1;
		prev = nullptr;
		next = nullptr;
	}
	Node(int Key, Node *Prev, Node *Next)
	{
		key = Key;
		prev = Prev;
		next = Next;
	}
	int GetKey()
	{
		return key;
	}
	void SetKey(int Key)
	{
		key = Key;
	}
	Node* &GetNextNode()
	{
		return next;
	}
	Node* &GetPreviousNode()
	{
		return prev;
	}
};

class List
{
	Node *head;
	Node *tail;
	int size;
	bool add(Node *node, int key);
	bool del(Node *node);
	void recursiveDelete(Node *node);
	void recursiveDelete(Node *start, Node *end);
	Node *Find(int key);
	Node *Find(Node *node);
public:
	List();
	List(int size);
	List(List& source);
	~List();
	void InputList(int size);
	void PrintList();
	void AddToTail(int k);
	void DelToTail();
	void AddToHead(int k);
	void DelToHead();
	void AddToIndex(int ind, int key);
	void DelToIndex(int ind);
	void AddToKey(int searchingKey, int key);//searching ключ узел с которым мы ищем (Искомый)
	void DelToKey(int searchingKey);
	void Clear();
	void operator=(List &source);
	List& operator+(List Second);
	void operator+=(List Second);
	int& operator[](int ind);//поиск по индексу(вернем адрес элемнта по индексу, чтоб его задать)
	bool Empty(); //проверка на пустоту
	bool operator==(List); //проверка на равенство
	Node* FindPosition(int);
	Node* Max();
	Node* Min();
	void AddToHead(List); //добавление списка в голову
	Node* FindKey(int); //поиск элемента по заданному ключу

	friend std::ostream & operator <<(std::ostream &r, List &s)
	{
		s.PrintList();
		return r;
	}

	friend std::istream & operator >> (std::istream&r, List&s)
	{
		int n;
		std::cin >> n;
		s.InputList(n);
		return r;
	}
};