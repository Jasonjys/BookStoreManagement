#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "Course.h"

//This is a doubly linked list

//Member functions:
//overloaded += function takes a T type and add it to the end of the list
//overloaded -= function takes a T type and remove it from the list
//overloaded += function takes a dlist of T type and addes it to the end of the original list
//overloaded -= function takes a dlist of T type and removes it from the original list
//cleanUp function delete all the data in the list

//Assumption: Assume the user of the dlist class overload the += operater for the T type so 
//it can call string += data and writes the data to the string
template <class T>
class Dlist
{
	template <class V>
	friend string& operator<<(string&, Dlist<V>&);
	class Node
	{
		friend class Dlist;
	private:
		T data;
		Node*    next;
		Node*    prev;
	};
public:
	Dlist();
	~Dlist();
	void add(T);
	void del(T);
	T    getData(int);
	void stringForward(string&);
	void stringBackward(string&);
	void cleanUp();
	int  getSize();
	Dlist<T>& operator+=(T);
	Dlist<T>& operator-=(T);
	Dlist<T>& operator+=(Dlist<T>&);
	Dlist<T>& operator-=(Dlist<T>&);
private:
	Node* head;
	int size;

};

template <class T>
Dlist<T>::Dlist() : head(0) {
	size = 0;
}

//destructor only clean up all the nodes but not all the data
template <class T>
Dlist<T>::~Dlist()
{
	Node* currNode = head;
	Node* nextNode;

	while (currNode != 0) {
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}


//Clean up function loops through the list and free all the data
//this has to be done seperately since we have multiple lists point to
//the same data
template <class T>
void	Dlist<T>::cleanUp()
{
	Node* currNode = head;
	Node* nextNode;

	while (currNode != 0) {
		nextNode = currNode->next;
		delete currNode->data;
		currNode = nextNode;
	}
}

template <class T>
int 	Dlist<T>::getSize()        { return size; }

//overload the += operator which takes a course pointer
template <class T>
Dlist<T>&	Dlist<T>::operator+=(T data)
{
	this->add(data);
	return (*this);
}

//overload the -= operator which takes a course pointer
template <class T>
Dlist<T>&	Dlist<T>::operator-=(T data)
{
	this->del(data);
	return (*this);
}

//overload the -= operator which takes a Dlist reference
//loop through the templist and add course pointers to the original list
template <class T>
Dlist<T>&	Dlist<T>::operator+=(Dlist& list)
{
	Node* currNode = list.head;
	while(currNode != 0)
	{
		(*this) += currNode->data;
		currNode = currNode->next;
	}
	return (*this);
}

//overload the -= operator which takes a Dlist reference
//loop through the templist and remove course pointers from the original list
template <class T>
Dlist<T>&	Dlist<T>::operator-=(Dlist& list)
{
	Node* currNode = list.head;
	while(currNode != 0)
	{
		(*this) -= currNode->data;
		currNode = currNode->next;
	}

	return (*this);
}

//overload << operator so we can wirte info to the string
template <class T>
string& operator<<(string& outStr, Dlist<T>& list)
{
	list.stringForward(outStr);
	list.stringBackward(outStr);
	return outStr;
}

//the getCourse function takes an index and return a course pointer
template <class T>
T	Dlist<T>::getData(int i)
{
	Node* currNode = head;
	int currIndex = 0;
	while(currIndex++ != i)
	{
		currNode = currNode->next;
	}
	return currNode->data;
}

//add function takes a course pointer and add the course to the list 
//based on its course code
template <class T>
void Dlist<T>::add(T data)
{
	Node* currNode;
	//Node* prevNode;

	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = 0;
	newNode->prev = 0;

	//prevNode = 0;
	currNode = head;

	if(head == 0)
	{
		head = newNode;
		return;
	}
	else
	{
		while (currNode->next != 0) 
		{
			currNode = currNode->next;
		}
	}
	currNode->next = newNode;
	newNode->prev = currNode;
	size++;
}

//del function takes a course pointer and remove the course from the list
template <class T>
void Dlist<T>::del(T data)
{
	Node* currNode = head;
	Node* prevNode = 0;

	while (currNode != 0)
	{
		if(data == currNode->data)
			break;
		prevNode = currNode;
		currNode = currNode->next;
	}

	if(prevNode == 0)
	{
		head = currNode->next;
	}
	else
	{
		prevNode->next = currNode->next;
	}

	if(currNode->next != 0)
	{
		currNode->next->prev = prevNode;
	}

	delete currNode->data;
	delete currNode;
	size--;
}

//this founction takes a string reference and write all the course info
//to the string from the head
template <class T>
void Dlist<T>::stringForward(string& output)
{
	output += "\nPrinting all the element forward:\n";
	if(head == 0)
	{
		output += "No element exists\n";
		return;
	}

	Node* currNode = head;

	while(currNode != 0)
	{
		output += *(currNode->data);
		currNode = currNode->next;
	}
	output += "======================================\n";
}

//this founction takes a string reference and write all the course info
//to the string from the tail
template <class T>
void Dlist<T>::stringBackward(string& output)
{
	output += "\nPrinting all the element backward:\n";
	if(head == 0)
	{
		output += "No element exists\n";
		return;
	}

	Node* currNode = head;
	string result;
	while(currNode != 0)
	{
		if(currNode->next == 0)
		{
			break;
		}
		currNode = currNode->next;
	}

	while(currNode != 0)
	{
		output += *(currNode->data);
		currNode = currNode->prev;
	}
	output += "======================================\n";
}

#endif
