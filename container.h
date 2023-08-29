#pragma once
#include<iostream>

using namespace std;

struct record
{
	string nameRec;
	string name2Rec;
	string ageRec;
	string heightRec;
	string weightRec;
	string end_weightRec;
	record* next = nullptr;
	record* prev = nullptr;
};

template<class T>
class list
{
private:
	int size = 0;
	T* head = nullptr;
	T* tail = nullptr;
public:
	~list();
	void push_front(T* value);
	void push_back(T* value);
	T* begin() { return head; }
	T* end() { return tail; }
	int GetSize() { return this->size; }
	class iterator
	{
	private:
		T* node;
	public:
		iterator() :node(0) {};
		iterator(record* other) :node(other) {};
		iterator(const iterator& it) :node(it.node) {};  //конструктор копирования
		iterator& operator=(const iterator& other) { node = other.node; return *this; }
		bool operator==(const iterator& it)const { return node == it.node; }
		bool operator!=(const iterator& it)const { return !(node == it.node); }
		iterator& operator++() { node = node->next; return *this; }
		T& operator*()const { return *node; }
	};

};

template<class T>
list<T>::~list()
{
	T* tmp = tail;
	for (size_t i = size; i > 0; i--)
		if (i == 1)
			delete head;
		else
		{
			T* tmp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete tmp;
		}
}

template<class T>
void list<T>::push_back(T* value)
{
	record* Rec = new record;
	Rec->nameRec = value->nameRec;
	Rec->name2Rec = value->name2Rec;
	Rec->ageRec = value->ageRec;
	Rec->heightRec = value->heightRec;
	Rec->weightRec = value->weightRec;
	Rec->end_weightRec = value->end_weightRec;
	if (!head && !tail) {
		head = Rec;
		tail = head;
	} else {
		Rec->prev = tail;
		tail->next = Rec;
		tail = Rec;
	} size++;
}

template <class T>
void list<T>::push_front(T* value)
{
	record* Rec = new record;
	Rec->nameRec = value->nameRec;
	Rec->name2Rec = value->name2Rec;
	Rec->ageRec = value->ageRec;
	Rec->heightRec = value->heightRec;
	Rec->weightRec = value->weightRec;
	Rec->end_weightRec = value->end_weightRec;
	if (!head && !tail) head = tail = Rec;
	else {
		Rec->prev = nullptr;
		Rec->next = head;
		head->prev = Rec;
		head = Rec;
	} size++;	
}
