//Niloufar Shamloo
//Project 1
//Damir Pulatov helped me. 
// 10/26/18
#include <iostream>
using namespace std;

class Node
{
public:
	Node * next;
	double reading;
};

class LinkedList
{
public:
	Node* head;
	Node* next;
	LinkedList();
	~LinkedList();
	void addNode(double);

private:
	int length;

};