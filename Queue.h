#pragma once
#include <iostream>
#include <memory>
using namespace std;

template <class Datatype>
struct Node
{
	// info part of the node
	Datatype Info;
	// Next part of the node that points to the next node
	shared_ptr<Node<Datatype>> Next;

};
// using datatype as class template for class Queue
template <class Datatype>
class PullQueue
{
	// private section of class
private:
	// front pointer that points to the first node on the linked list
	shared_ptr <Node<Datatype>> FrontPointer;
	// back pointer that points to the back of the linked list
	shared_ptr <Node<Datatype>> BackPointer;
	//Public section of the class
public:
	// function that checks if linked list is empty
	bool isEmpty();
	// void function that adds an item to the linked list and points Back pointer to it
	void enqueue(Datatype& element);
	// bool dequeue function that takes the first element off the linked list
	bool dequeue(Datatype& element);
	// peek function that copies the first element of the linked list
	bool peek(Datatype& element);
	// void function that prints the linked list
	void printQueue()
	{
		shared_ptr<Node<Datatype>> ptr(FrontPointer);
		while (ptr != nullptr)
		{
			cout << ptr->Info << "--> ";
			ptr = ptr->Next;
		}
		cout << "nullptr" << endl;
	}
	void printPullQueue()
	{
		cout << "Pull queue: ";
		shared_ptr<Node<Datatype>> ptr(FrontPointer);
		while (ptr != nullptr)
		{
			cout << "(" << ptr->Info.x << "," << ptr->Info.y << ")" << "->";
			ptr = ptr->Next;
		}
		cout << "nullptr" << endl;
	}
	bool pull(Datatype& item, Datatype& PulledItem);
	void MakeEmpty()
	{
		while (FrontPointer != nullptr)
		{
			FrontPointer = FrontPointer->Next;
		}
		BackPointer = FrontPointer;
	}


};
// isempty function that checks if linked list is empty
template <class Datatype>
bool PullQueue<Datatype>::isEmpty()
{
	// if front pointer is empty
	if (FrontPointer == nullptr)
		return true;
	return false;

}
template <class Datatype>
bool PullQueue<Datatype>::pull(Datatype& item, Datatype& PulledItem)
{
	if (FrontPointer == nullptr)
	{
		return false;
	}
	else if (item == FrontPointer->Info)
	{
		PulledItem = FrontPointer->Info;
		FrontPointer = FrontPointer->Next;
		if (FrontPointer == nullptr)
			BackPointer = FrontPointer;
		return true;
	}


	shared_ptr<Node<Datatype>> ptr(FrontPointer);

	for (; ptr->Next != nullptr; ptr = ptr->Next)
	{
		if (item == ptr->Next->Info)
		{

			PulledItem = ptr->Next->Info;

			ptr->Next = ptr->Next->Next;
			if (ptr->Next == nullptr)
				BackPointer = ptr;
			return true;
		}
	}
	return false;
}
// enqueue function
template <class Datatype>
void PullQueue<Datatype>::enqueue(Datatype& element)
{
	// declare a new node 
	shared_ptr<Node<Datatype>> NewNode{ new Node<Datatype> };
	// if front pointer is empty
	if (FrontPointer == nullptr)
	{
		NewNode->Info = element;
		// front pointer is going to be pointing to NewNode
		FrontPointer = NewNode;
		// front node will be pointing to Null Ptr
		FrontPointer->Next = nullptr;
		// BackPointer is pointing to front pointer
		BackPointer = FrontPointer;
	}
	else
	{
		// NewNode info is going to be element
		NewNode->Info = element;
		// BackPointer is going to point to the new node
		BackPointer->Next = NewNode;
		// The new node is going to be addressed to BackPointer
		BackPointer = NewNode;

	}



}
// dequeue function
template <class Datatype>
bool PullQueue<Datatype>::dequeue(Datatype& element)
{
	// if front pointer is not equal to nullptr
	if (FrontPointer != nullptr)
	{
		// element is going to get the address of frontpointer's info
		element = FrontPointer->Info;
		// Front pointer will be deleted
		FrontPointer = FrontPointer->Next;
		if (FrontPointer == nullptr)
		{
			BackPointer = FrontPointer;
		}
		//return true
		return true;
	}
	return false;

}
// peek function
template <class Datatype>
bool PullQueue<Datatype>::peek(Datatype& element)
{
	// if front pointer is not empty
	if (FrontPointer != nullptr)
	{
		// set element to what is stored in front pointer
		element = FrontPointer->Info;
		return true;
	}
	return false;

}
