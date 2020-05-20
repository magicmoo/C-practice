#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
template <typename Type>
class Node{
	public:
		Type date;
		Node* prev;
		Node* next;
};


#endif
