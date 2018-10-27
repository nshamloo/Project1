//Niloufar Shamloo
//Project 1
//Damir Pulatov helped me. 
// 10/26/18
#include "List.h"

LinkedList::LinkedList()
{
	length = 0; // make the length of linked list 0
	head = NULL;
}

LinkedList::~LinkedList()
{
}

void LinkedList::addNode(double num)
{
	Node* newNode = new Node(); // creating a new node
	newNode->reading = num; // adding a reading to that node
	if (head == NULL) // if the list is empty
	{
		head = newNode; // making the new node the head
		this->next = NULL; // linked to the second node which is empty
	}
	else
	 {
		Node* currentNode = head;
		while (currentNode->next != NULL) //while we are not at the end
		{
			currentNode = currentNode->next; //move forward
		}
		currentNode->next = newNode; // adding that node to the end of LL
		newNode->next = NULL; // pointing to nothing
	}
	length++;
}
