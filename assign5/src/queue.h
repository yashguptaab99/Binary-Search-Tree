//===================================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Implement binary search tree and perform following operations:
//					  a. Insert
//					  b. Delete
//					  c. Search
//					  d. Mirror image
//					  e. Display
//					  f. Display level wise traversals.
//===================================================================================

#ifndef QUEUE_H_
#define QUEUE_H_
#include "linked.h"
#include "linked.cpp"


template<typename T>
class queue {

	linked<T>l;   //object of linked list adt declared here to access
				  //public functions of that class

public:
	queue();
	virtual ~queue();
	bool isempty();
	T peep();
	void enqueue(T);
	T dequeue();

};

#endif /* QUEUE_H_ */
